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
#define PRONUM 12
#define CONSNUM 12
char * queuePath;


void* producer(void * arg) 
{   
	int fd ,ret,i;
	struct mqReg reg;
    fd=open(queuePath,O_WRONLY);
	if(fd==-1) {
		fprintf(stderr, "open error [%s]\n", queuePath);
		return NULL;
	}
	for(i=0;i<15;i++) {
		
		reg.data="hello world";
		reg.size=strlen(reg.data)+1;
		ret=ioctl(fd,MQ_SEND_MSG,&reg);
		if(ret==-1) {
		    fprintf(stderr, "ioctl error\n");
		    return NULL;
		}
	
	}
    ret=close(fd);
	if(ret==-1) {
		fprintf(stderr, "close error\n");
		return NULL;
	}
	return NULL;
}

void* consumer() 
{ int i,fd,ret;
  char* buffer=(char*)malloc(4096);
  fd=open(queuePath,O_RDONLY);
  if(fd==-1) {
    fprintf(stderr, "open error\n");
    return NULL;
    }
     for(i=0;i<15;i++)
    {     
        
        ret=ioctl(fd, MQ_RECV_MSG, buffer);
        if(ret==-1) {
            fprintf(stderr, "ioctl error\n");
            return NULL;
        }
        printf("The message is %s\n", buffer);
    
    }
      
    ret=close(fd);
    if(ret==-1) {
            fprintf(stderr, "close error\n");
            return NULL;
    }
  free(buffer);
   return NULL;

}
int main (int argc, char** argv)
{ 
    pthread_t produsers [PRONUM];
    pthread_t consumers [CONSNUM];
     int i ,j,w,z;
    if(argc>1) {
	    queuePath=argv[1];
    } else {
	    queuePath="/dev/QMsg0";
    }
    
    for(i=0;i<PRONUM;i++)
    {
         pthread_create(&produsers[i],NULL,producer,&i);
    }
 

   for(j=0;j<CONSNUM;j++)
    {
        pthread_create(&consumers[j],NULL,consumer,&j);
    }
  
    for(w=0;w<PRONUM;w++)
    {
        pthread_join(produsers[w],NULL);
    }
  

    for(z=0;z<CONSNUM;z++)
    {
        pthread_join(consumers[z],NULL);
    } 
 
   return 0;
}
