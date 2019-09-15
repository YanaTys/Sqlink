
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include<semaphore.h>
#include <pthread.h>
#include "producerCons.h"


Queue* createQueue(int capacity) 
{ 
    Queue* queue = (Queue*) malloc(sizeof(Queue)); 
    queue->capacity = capacity; 
    queue->array = malloc(queue->capacity * sizeof(void*)); 
    queue->front = 0;  
    queue->rear = 0; 
    queue->size=0;
   pthread_cond_init( &(queue->full), NULL);
   pthread_cond_init( &(queue->empety), NULL);
    pthread_mutex_init(&(queue->lock), NULL);
    
    return queue; 

} 

int isFull(Queue* queue)
{     if(queue->size == queue->capacity){
             return 1;
      }else{
          return 0;
      }
    
}
/* Queue is empty when size is 0 */
int isEmpty(Queue* queue)
{
    if(queue->size == 0){
             return 1;
      }else{
          return 0;
      }
}
int enqueue(Queue* queue, void * item) /*func to add item*/
{ 
  pthread_mutex_lock(&(queue->lock));
  while(queue->size==queue->capacity)
       {pthread_cond_wait( &(queue->empety), &(queue->lock));
       }
    queue->array[queue->rear] = item; 
    queue->rear = (queue->rear + 1)%queue->capacity; 
    queue->size++;
    pthread_cond_signal( &(queue->full));
    pthread_mutex_unlock(&(queue->lock));
   
    return 1;
} 
void * dequeue(Queue* queue) /*func to remove*/
{  
    void * item;
     pthread_mutex_lock(&(queue->lock));
    while(queue->size==0)
       {pthread_cond_wait( &(queue->full), &(queue->lock));
       }
   
    item = queue->array[queue->front]; 
    queue->front = (queue->front + 1)%queue->capacity; 
     queue->size--;
     pthread_cond_signal( &(queue->empety));
    pthread_mutex_unlock(&(queue->lock));
    
    return item; 

}
/* Function to get front of queue */
void * front(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return NULL; 
    return queue->array[queue->front]; 
} 
/* Function to get rear of queue */
void * rear(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return NULL; 
    return queue->array[queue->rear]; 
} 

