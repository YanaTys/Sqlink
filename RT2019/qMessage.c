#include <linux/module.h> /* for MODULE_*, module_* */
#include <linux/moduleparam.h> /* for module_param, MODULE_PARM_DESC */
#include <linux/fs.h> /* for fops */
#include <linux/device.h> /* for class_create */
#include <linux/slab.h> /* for kmalloc, kfree */
#include <linux/cdev.h> /* for cdev_* */
#include <linux/sched.h> /* for TASK_INTERRUPTIBLE and more constants */
#include <linux/spinlock.h> /* for spinlock_t and ops on it */
#include <linux/wait.h> /* for wait_queue_head_t and ops on it */
#include <linux/uaccess.h> /* for copy_to_user, access_ok */
#include <linux/list.h>
#include "qMessage.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yana Tyshkevych");
MODULE_DESCRIPTION("queues messages exercise");
MODULE_VERSION("1.12.44b");

static int queues_count = 8;
static dev_t first_dev;

struct messageQu {
	struct list_head list;
	size_t size;
	size_t capacity;
	struct device *mq_device;
	wait_queue_head_t smi_busy_wait;
	struct mutex lock;
};
	
static struct messageQu * m_queues;
static int first_minor;
static struct class *my_class;
static struct cdev cdev;

struct list_struct {
	struct list_head node;
	char * data;
	size_t size;
};

static inline void m_queue_ctor(struct messageQu* m_queue)
{
	m_queue->size = 0;
	m_queue->capacity = 100;
	INIT_LIST_HEAD(&m_queue->list);
	m_queue->mq_device=NULL;
	init_waitqueue_head(&m_queue->smi_busy_wait);
	mutex_init(&m_queue->lock);
}

static inline void m_queue_dtor(struct messageQu * m_queue)
{		struct list_struct* new_list_struct;
		list_for_each_entry(new_list_struct,&m_queue->list,node)
		{
			kfree(new_list_struct->data);
			kfree(new_list_struct);
		}
		mutex_destroy(&m_queue->lock);
}

static int queue_open(struct inode *inode, struct file *filp)
{	
	int queue_num=iminor(inode)-MINOR(first_dev);
	filp->private_data=m_queues+queue_num;
	return 0;
}

static long queue_ioctl( struct file *filp, unsigned int op, unsigned long buffer_usr)
{
	struct messageQu * mQueues =filp->private_data;
	int ret;
	char * buffer;
	struct mqReg reg;
	struct mqReg* regP=(struct mqReg*)buffer_usr;
	struct list_struct* new_list_struct;
	int size;
	switch(op){
		case MQ_SEND_MSG:
			wait_event_interruptible(mQueues->smi_busy_wait,mQueues->size<mQueues->capacity);
			ret = copy_from_user(&reg,regP,sizeof(reg));
			if(ret)
			{
				pr_err("%s: copy from user\n", THIS_MODULE->name);
				return ret;
			}
			pr_info("%s: copy from user\n", THIS_MODULE->name);
			buffer=kmalloc(reg.size, GFP_KERNEL);
			if (IS_ERR(buffer)) {
				pr_err("%s: kmalloc\n", THIS_MODULE->name);
				ret = PTR_ERR(buffer);
				return ret;
			}
			ret = copy_from_user(buffer,reg.data,reg.size);
			if(ret)
			{
				pr_err("%s: copy from user\n", THIS_MODULE->name);
				return ret;
			}
			new_list_struct =kmalloc(sizeof(struct list_struct), GFP_KERNEL);
			if (IS_ERR(new_list_struct)) {
				pr_err("%s: kmalloc\n", THIS_MODULE->name);
				ret = PTR_ERR(new_list_struct);
				return ret;
			}

			new_list_struct->data=buffer;
			new_list_struct->size=reg.size;
			ret=mutex_lock_interruptible(&mQueues->lock);
			if(ret)
			{
				pr_err("%s: mutex\n", THIS_MODULE->name);
			}
			list_add_tail(&new_list_struct->node,&mQueues->list);
			mQueues->size++;
			pr_info("%s: added element to list\n", THIS_MODULE->name);
			mutex_unlock(&mQueues->lock);
			wake_up_interruptible(&mQueues->smi_busy_wait);
			return reg.size;
			break;
		case MQ_RECV_MSG:
			
			wait_event_interruptible(mQueues->smi_busy_wait,list_empty(&mQueues->list)==0);
			ret=mutex_lock_interruptible(&mQueues->lock);
			if(ret)
			{
				pr_err("%s: mutex\n", THIS_MODULE->name);
			}
			new_list_struct=list_entry((&mQueues->list)->prev,struct list_struct,node);
			list_del_init((&mQueues->list)->prev);
			size=new_list_struct->size;
			ret=copy_to_user((char*)buffer_usr,new_list_struct->data,new_list_struct->size);
			if(ret)
			{
				pr_err("copy from user\n");
				return ret;
			}
			mutex_unlock(&mQueues->lock);
			kfree(new_list_struct->data);
			kfree(new_list_struct);
			mQueues->size--;
			wake_up_interruptible(&mQueues->smi_busy_wait);
			return size;
			break;
		default:
			return -ENOTTY;
	}
	return -ENOTTY;
}

/*static int queue_release(struct inode *inode, struct file *filp)
{mi_busy_wait
	struct messageQu *m_queues;
	pipe = (struct messageQu*)(filp->private_data);
	pipe_lock(pipe);
	if (filp->f_mode & FMODE_READ)
		pipe->readers--;
	if (filp->f_mode & FMODE_WRITE),mQueues->size==0
		pipe->writers--;

	if (filp->f_mode & FMODE_WRITE) {
		if (pipe->writers == 0) {
			pr_debug("pipe_release: no more writers, waking up readers...\n");
			pipe_wake_readers(pipe);
		}
	}
	pipe_unlock(pipe);
	return 0;
}*/
static const struct file_operations queue_fops = {
	.owner = THIS_MODULE,
	.open = queue_open,
	.unlocked_ioctl=queue_ioctl,
	/*.release = queue_release,*/

};
static int __init queue_init(void)
{
	int ret;
	int i;
	
	m_queues = kmalloc(sizeof(struct messageQu)*queues_count, GFP_KERNEL);
	if (IS_ERR(m_queues)) {
		pr_err("kmalloc\n");
		ret = PTR_ERR(m_queues);
		goto err_return;
	}
	for (i = 0; i < queues_count; i++) {
		m_queue_ctor(m_queues+i);
	}
	ret = alloc_chrdev_region(&first_dev, first_minor, queues_count, THIS_MODULE->name);
	if (ret) {
		pr_err("cannot alloc_chrdev_region\n");
		goto err_final;
	}
	pr_debug("allocated the region\n");
	
	cdev_init(&cdev, &queue_fops);
	
	ret = cdev_add(&cdev, first_dev, queues_count);
	if (ret) {
		pr_err("cannot cdev_add\n");
		goto err_dealloc;
	}
	pr_debug("added the cdev\n");
	
	my_class = class_create(THIS_MODULE, THIS_MODULE->name);

	if (IS_ERR(my_class)) {
		pr_err("class_create\n");
		ret = PTR_ERR(my_class);
		goto err_cdev_del;
	}
	pr_debug("created the class\n");

	for (i = 0; i < queues_count; i++) {
		
		m_queues[i].mq_device = device_create(my_class, NULL,
			MKDEV(MAJOR(first_dev), MINOR(first_dev)+i),
			NULL, "%s%d", THIS_MODULE->name, i);
		if (IS_ERR(m_queues[i].mq_device)) {
			pr_err("device_create\n");
			ret = PTR_ERR(m_queues[i].mq_device);
			goto err_class;
		}
	}
	pr_info(KBUILD_MODNAME " loaded successfully\n");
	return 0;
	
	err_class:
	class_destroy(my_class);
	err_cdev_del:
	cdev_del(&cdev);
	err_dealloc:
	unregister_chrdev_region(first_dev,queues_count);
    err_final:
	for (i = 0; i < queues_count; i++)
		m_queue_dtor(m_queues+i);
	kfree(m_queues);
    err_return:
	return ret;

}

static void __exit queue_exit(void)
{
	int i;
	for (i = 0; i < queues_count; i++)
		device_destroy(my_class, MKDEV(MAJOR(first_dev),
			MINOR(first_dev)+i));
	class_destroy(my_class);
	cdev_del(&cdev);
	unregister_chrdev_region(first_dev, queues_count);
	for (i = 0; i < queues_count; i++)
		m_queue_dtor(m_queues+i);
	kfree(m_queues);
	pr_info(KBUILD_MODNAME " unloaded successfully\n");
}

module_init(queue_init);
module_exit(queue_exit);
