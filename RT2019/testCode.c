#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<semaphore.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "qMessage.h"
/*#define MESSEGE 5*/
#define PRONUM 100
#define CONSNUM 100



void* producer(void * arg) 
{   
    int fd ,ret;
  
    struct mqReg reg;
  
     while(1)
    {
        fd=open("/dev/QMsg0",O_WRONLY);
        if(fd==-1) {
            fprintf(stderr, "open error\n");
            return (void*)1;
        }
        reg.data="hello world";
        reg.size=strlen(reg.data);
        ret=ioctl(fd,MQ_SEND_MSG,&reg);
        if(ret==-1) {
            fprintf(stderr, "ioctl error\n");
            return (void*)1;
        }
        /*printf("return value from ioctl was %d\n", ret);*/
        ret=close(fd);
        if(ret==-1) {
            fprintf(stderr, "close error\n");
            return (void*)1;
        }
     
    }
   
}

void* consumer() 
{ 
    while (1) 
    {     
         int fd, ret;
        char* buffer=(char*)malloc(4096);
        fd=open("/dev/QMsg0",O_RDONLY);
        if(fd==-1) {
            fprintf(stderr, "open error\n");
        return (void*)1;
        }
        ret=ioctl(fd, MQ_RECV_MSG, buffer);
        if(ret==-1) {
            fprintf(stderr, "ioctl error\n");
        return (void*)1;
        }
        printf("The message is %s\n", buffer);
        ret=close(fd);
        if(ret==-1) {
            fprintf(stderr, "close error\n");
            return (void*)1;
        }
    }
}
int main ()
{ 
    pthread_t produsers [PRONUM];
    pthread_t consumers [CONSNUM];
   
    int i ,j,w,z;

    for(i=0;i<PRONUM;i++)
    {
         pthread_create(&produsers[i],NULL,producer,&i);
          
     
    }
   for(j=0;j<CONSNUM;j++)
    {
        pthread_create(&consumers[j],NULL,consumer,&j);
    }
    
    for(w=1;w<=PRONUM;w++)
    {
        pthread_join(produsers[w],NULL);
    }
   

    for(z=1;z<=CONSNUM;z++)
    {
        pthread_join(consumers[z],NULL);
    }
   return 0;
}