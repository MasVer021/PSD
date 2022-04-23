#include "item.h"

typedef struct c_queue *queue;

queue newQueue(void);

int emptyQueue(queue q);

item dequeue(queue q);

int enqueue(item val, queue q);

void outputStack(queue q);
