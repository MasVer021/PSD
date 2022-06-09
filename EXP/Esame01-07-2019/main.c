#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "item.h"



int main(void)
{
  queue q = newQueue() ;
  queue q2 = newQueue() ;

  enqueue(creaItem(1),q);
  enqueue(creaItem(2),q);
  enqueue(creaItem(3),q);
  enqueue(creaItem(4),q);
  enqueue(creaItem(5),q);
  enqueue(creaItem(6),q);
  enqueue(creaItem(7),q);
  enqueue(creaItem(8),q);


  enqueue(creaItem(1),q2);
  enqueue(creaItem(2),q2);
  enqueue(creaItem(3),q2);
  enqueue(creaItem(4),q2);
  enqueue(creaItem(9),q2);
  enqueue(creaItem(10),q2);
  enqueue(creaItem(6),q2);
  enqueue(creaItem(45),q2);

  outputStack(q);
  cancFinoItem(creaItem(4),q);
  outputStack(q);

  outputStack(fondiDaItem(creaItem(4),q,q2));

  return 0;
}
