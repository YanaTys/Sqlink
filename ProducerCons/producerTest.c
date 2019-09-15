#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include<semaphore.h>
#include<pthread.h>
#include <string.h> 
#include "producerCons.h"
#define MESSEGE 5
#define PRONUM 5
#define CONSUM 10
Queue * q;
sem_t sem;
 void * producer(void * arg) 
{
        int index=*((int*)arg);
        int i=0,error;
        char item[100];
        for(i=0;i<MESSEGE;i++){
              sprintf(item,"the id msg is %d",index);
              error=enqueue(q,item);
              if(error==1){
                  printf("\n%s\n",item);
              }
              
        }
      
}

void * consumer(void * arg) 
{    char item[100];
     int flag=0;
    while (1) 
    {   flag=0;
        strcpy(item,(char *)dequeue(q));
        if(strcmp(item,"stop")==0){
            enqueue(q,item);
            flag=1;
        }
         if(flag==0){
             printf("\ni read messege %s\n",item);
         }else{
            printf("\nstop!!!\n");
            break; 
         }
       
    }
}
 int main(){
    pthread_t producers [PRONUM];
    pthread_t consumers [CONSUM];
    int i,j,w,z;
    void * status;
    char stop [100]="stop";
    int p[PRONUM];
    int c[CONSUM];
    q=createQueue(7);
    for(i=0;i<PRONUM;i++){
        p[i]=i;
    }
     for(i=0;i<CONSUM;i++){
        c[i]=i;
    }
    
    for(i=0;i<PRONUM;i++){
        status = pthread_create(&producers[i],NULL, producer, &p[i]);
       
    }

    for(j=0;j<CONSUM;j++){
        status = pthread_create(&consumers[j],NULL, consumer, NULL);
        
    }
   
    for(w=0;w<PRONUM;w++){
     pthread_join(producers[w], NULL);
    }
    
    enqueue(q,stop);
    

     for(z=0;z<CONSUM;z++){
     pthread_join(consumers[z], NULL);
    }
   pthread_cond_destroy(&(q->empety));
   pthread_cond_destroy(&(q->full));
   free(q->array);
   free(q);
    


     return 0;
 }