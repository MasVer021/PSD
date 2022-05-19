typedef struct c_queue *queue;

queue newQueue(void);

int emptyQueue(queue q);

void * dequeue(queue q);

int enqueue(void* val, queue q);
