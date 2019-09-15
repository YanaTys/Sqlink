#ifndef H_P
#define H_P
struct Queue 
{ 
    int front;
    int rear;
    int size; 
    int capacity;  
    pthread_cond_t empety;
    pthread_cond_t full;
    pthread_mutex_t lock; 
    void** array; 
}; 
typedef struct  Queue Queue;
Queue* createQueue(int capacity);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
int enqueue(Queue* queue, void * item);
void * dequeue(Queue* queue);
void * front(Queue* queue);
void * rear(Queue* queue);


#endif