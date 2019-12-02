#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <limits.h>
#include <semaphore.h>
#include <glib.h>
#include <gmodule.h>
GSList *list;
sem_t empety;
sem_t full;
pthread_mutex_t lock;
void* producerFunc(void *arg)
{
    int fd, ret, dataSize;
    char *buff=malloc(20);
    char *ptr;
    int msgSize = 20;    
    err(fd = open("/dev/urandom", O_RDONLY));
    while (1)
    {
        dataSize = 0;
        ptr = buff;
        do
        {
            ret = read(fd, ptr, msgSize - dataSize);
            if(ret<0){
                 fprintf(stderr, "there was a pthread error %d\n", ret);
                 exit(EXIT_FAILURE);
            }
            dataSize += ret;
            ptr += ret;
        } while (dataSize < msgSize);
        sem_wait(&empety);
        pthread_mutex_lock(&lock);
        list = g_slist_prepend(list, buff);
        pthread_mutex_unlock(&lock);
        sem_post(&full);
        sleep(1);
    }
    free(buff);
    err(close(fd));
    return NULL;
}
void* consumer(void *arg)
{
    int fd;
    char *str = (char *)malloc(20);
    GSList * temp;    
    while(1){
        sem_wait(&full);
        pthread_mutex_lock(&lock);
        temp=g_slist_last (list);
        g_slist_delete_link (list,g_slist_last (list));
        pthread_mutex_unlock(&lock);
        sem_post(&empety);
        temp->data++;    }      
    free(str);
    err(close(fd));
    return NULL;
}
static void check_pthread_error(int ret)
{
    if (ret)
    {
        fprintf(stderr, "there was a pthread error %d\n", ret);
        exit(EXIT_FAILURE);
    }
}
int main(int argc, char **argv, char **envp)
{
    pthread_t producer;
    pthread_t consumers[2];
    cpu_set_t  mask;
    CPU_ZERO(&mask);    
    int ret; 
    int i;
    ret = pthread_create(&producer, NULL, producerFunc, NULL);
    check_pthread_error(ret);

    sem_init(&empety,0,20);
    sem_init(&full,0,0);

    pthread_mutex_init(&lock, NULL);    
    for (i = 0; i < 2; i++)
    {   CPU_SET(i, &mask);
        ret = pthread_create(&consumers[i], NULL, consumer, NULL);
        check_pthread_error(ret);
    }    
    ret=pthread_join(producer, NULL);
    check_pthread_error(ret);    
    for ( i = 0; i < 2; i++)
    {
        ret = pthread_join(consumers[i], NULL);
        check_pthread_error(ret);
    }
    return EXIT_SUCCESS;
}