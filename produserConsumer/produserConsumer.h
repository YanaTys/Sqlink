#ifndef H_PRODCONS
#define H_PRODCONS
struct Queue
{
   int front, rear;
   int size;
   int capacity;
   sem_t empety;
   sem_t full;
   pthread_mutex_t lock;
   void** array;
 
};
typedef struct  Queue Queue;
Queue* createQueue(int capacity);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
int enqueue(Queue* queue, void* item); /*func to add item*/
void* dequeue(Queue* queue); /*func to remove*/
void* front(Queue* queue);
void* rear(Queue* queue);
int destroy(Queue* queue);



#endif