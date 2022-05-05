#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "item.h"




int main(void)
{
  queue q = newQueue() /*codaPunti()*/;
  queue q2=newQueue();

  enqueue(creaItem(1,10),q);
  enqueue(creaItem(2,3),q);
  enqueue(creaItem(3,8),q);
  enqueue(creaItem(4,5),q);
  enqueue(creaItem(-9,12),q);

  outputStack(q);

  q2=reverseQueue(q);
  outputStack(q2);


}
