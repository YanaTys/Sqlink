
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
#define MAXINT 4096
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yana Tyshkevych");
MODULE_DESCRIPTION("queues messages exercise");
MODULE_VERSION("1.12.44b");
static int pages_count = 8;
static dev_t first_dev;

struct messageQu {
	struct list_head list;
    size_t size;
    size_t capacity;
    struct device *mq_device;
	};
	
static struct messageQu * m_queues;
static int first_minor;
static struct class *my_class;
static struct cdev cdev;

struct node{
	struct list_head node;
	char * data;
	};

struct mqBuffer{
	size_t size;
	char * data;
	};

struct node node_new;

static inline void m_queues_ctor(struct messageQu * m_queues)
{	m_queues->size = 0;
    m_queues->capacity = 100;
    INIT_LIST_HEAD(&(m_queues->list));
    m_queues->mq_device=NULL;
}
static const struct file_operations queue_fops = {
	.owner = THIS_MODULE,
	.open = queue_open,
	.release = queue_release,

};

static inline void m_queues_dtor(const struct messageQu *m_queues)
{

}
static int queue_open(struct inode *inode, struct file *filp)
{
	return 0;
}
static int queue_ioctl(struct inode *inode, struct file *filp, unsigned int op, unsigned long buffer_usr)
{
	int the_queue_number = iminor(inode)-MINOR(first_dev);
	struct messageQu * mQueues = m_queues+the_pipe_number;
	int ret;
	char* buffer;
	void __user *buffer_usrp =(void __user *)buffer_usr;
	switch(op){
		case 1:
			buffer=kmalloc(sizeof(struct messageQu)*MAXINT, GFP_KERNEL);
			if (IS_ERR(m_queues)) {
				pr_err("kmalloc\n");
				ret = PTR_ERR(m_queues);
				goto err_return;
				}
			ret = copy_from_user(buffer,buffer_usr,MAXINT);
			if(ret==0)
			{
				node_new=kmalloc(sizeof(struct node), GFP_KERNEL);
				if (IS_ERR(node_new)) {
				pr_err("kmalloc\n");
				ret = PTR_ERR(node_new);
				goto err_return;
			}
			node_new->data=buffer;
			list_add_tail(&(node_new->node),&(mQueues->head));
			mQueues->size++;
			break;
		case 2:
			buffer=kmalloc(sizeof(struct messageQu)*MAXINT, GFP_KERNEL);
			if (IS_ERR(m_queues)) {
				pr_err("kmalloc\n");
				ret = PTR_ERR(m_queues);
				goto err_return;
				}
			ret = copy_from_user(buffer,buffer_usr,MAXINT);
			break;
		
				
}

static int queue_release(struct inode *inode, struct file *filp)
{
	struct messageQu *m_queues;
	pipe = (struct messageQu*)(filp->private_data);
	pipe_lock(pipe);
	if (filp->f_mode & FMODE_READ)
		pipe->readers--;
	if (filp->f_mode & FMODE_WRITE)
		pipe->writers--;
	/* wake up readers since they may want to end if there
	are no more writers...
	*/
	if (filp->f_mode & FMODE_WRITE) {
		if (pipe->writers == 0) {
			pr_debug("pipe_release: no more writers, waking up readers...\n");
			pipe_wake_readers(pipe);
		}
	}
	pipe_unlock(pipe);
	return 0;
}

static int __init queue_init(void)
{
	int ret;
	int i;
	
	m_queues = kmalloc(sizeof(struct messageQu)*pages_count, GFP_KERNEL);
	if (IS_ERR(m_queues)) {
		pr_err("kmalloc\n");
		ret = PTR_ERR(m_queues);
		goto err_return;
	    }
		for (i = 0; i < pages_count; i++)
			m_queues_ctor(m_queues+i);
	   
    ret = alloc_chrdev_region(&first_dev, first_minor, pages_count,
			THIS_MODULE->name);
	if (ret) {
		pr_err("cannot alloc_chrdev_region\n");
		goto err_final;
	}
	pr_debug("allocated the region\n");
	
	cdev_init(&cdev, &queue_fops);

	ret = cdev_add(&cdev, first_dev, pages_count);
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

	for (i = 0; i < pages_count; i++) {
		
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
	unregister_chrdev_region(first_dev,pages_count);
    err_final:
	for (i = 0; i < pages_count; i++)
		m_queues_dtor(m_queues+i);
	kfree(m_queues);
    err_return:
	return ret;

}

static void __exit queue_exit(void)
{
	int i;
	for (i = 0; i < pages_count; i++)
		device_destroy(my_class, MKDEV(MAJOR(first_dev),
			MINOR(first_dev)+i));
	class_destroy(my_class);
	cdev_del(&cdev);
	unregister_chrdev_region(first_dev, pages_count);
	for (i = 0; i < pages_count; i++)
		m_queues_dtor(m_queues+i);
	kfree(m_queues);
	pr_info(KBUILD_MODNAME " unloaded successfully\n");
}

module_init(queue_init);
module_exit(queue_exit);
