#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<semaphore.h>
#include <pthread.h>
#include <string.h>
#include "produserConsumer.h"
#define MESSEGE 5
#define PRONUM 10
#define CONSNUM 15


 Queue* que;
 sem_t semofor;

void* producer(void * arg) 
{   int item= *((int* )arg);

    int i=0;
    int error;
    sem_post(&semofor);
    /*char item [512]="i an thread number ";
    strcat(str,idex)*/
     for(i=0;i<MESSEGE;i++)
        {
            
            sem_wait(&(que->empety));
            pthread_mutex_lock(&(que->lock));
            error=enqueue(que, &item); 
            pthread_mutex_unlock(&(que->lock));
            if(error==1)
                printf("%d\n",item);
            sem_post(&que->full);
        }
   
}

void* consumer() 
{   int item,flag=0;
    while (1) 
    {       flag=0;
            sem_wait(&que->full);
            pthread_mutex_lock(&(que->lock));
            item =*((int*)(dequeue(que))); 
            pthread_mutex_unlock(&(que->lock));
            if(item==-1)
               {
                 enqueue(que, &item);  
                 flag=1; 
               }
            printf("read the messege \n");
            sem_post(&(que->empety));
            if(flag==1)
            {    printf("stop\n");
                 pthread_exit(NULL);
                /* break;*/
            }

    }
}
int main ()
{ 
    pthread_t produsers [PRONUM];
    pthread_t consumers [CONSNUM];
    void * status;
    int i ,j,w,z,stop=-1;
    sem_init(&semofor,0,1);
    que=createQueue(7);

    for(i=0;i<PRONUM;i++)
    {
         pthread_create(&produsers[i],NULL,producer,&i);
         sem_wait(&semofor);
    }
   for(j=0;j<CONSNUM;j++)
    {
        pthread_create(&consumers[j],NULL,consumer,&j);
    }
    
    for(w=1;w<=PRONUM;w++)
    {
        pthread_join(produsers[w],NULL);
    }
    enqueue(que, &stop);

    for(z=1;z<=CONSNUM;z++)
    {
        pthread_join(consumers[z],NULL);
    }
    sem_destroy(&(que->empety));
    sem_destroy(&(que->full));
    destroy(que);
}
