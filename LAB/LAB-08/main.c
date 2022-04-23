#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "item.h"

queue codaPunti(void);
queue * sottoCode(queue q);
float spezzata (queue q);
queue concatenazione(queue q1, queue q2);
void schedulingProcessi(queue q,int cicliCPU);


int main(void)
{
  queue q = newQueue() /*codaPunti()*/;
  queue q2=newQueue();

  /*enqueue(creaItem(-6,8),q);
  enqueue(creaItem(-6,-6),q);
  enqueue(creaItem(1,2),q);
  enqueue(creaItem(3,4),q);
  enqueue(creaItem(-9,5),q);
  enqueue(creaItem(-9,6),q);
  enqueue(creaItem(1.3,6.3),q);
  enqueue(creaItem(-7,-10),q);
  enqueue(creaItem(-4,2),q);
  enqueue(creaItem(6,-3),q);
  enqueue(creaItem(-1,-9),q);
  enqueue(creaItem(7,3),q);
  enqueue(creaItem(4,-14),q);

  queue * sq = sottoCode(q);
  printf("%g\n",spezzata(sq[2]));
  outputStack(sq[2]);

  q2 = concatenazione(sq[3],sq[2]);
  q2 = concatenazione(q2,sq[1]);
  q2 = concatenazione(q2,sq[0]);

  outputStack(q2);*/

  enqueue(creaItem(1,10),q);
  enqueue(creaItem(2,3),q);
  enqueue(creaItem(3,8),q);
  enqueue(creaItem(4,5),q);
  schedulingProcessi(q,4);


}

queue codaPunti(void)
{
  queue q;
  item it,s;

  q = newQueue();

  it =input_item();
  s = creaItem(0,0);


  while(!eq(it,s))
  {
    enqueue(it,q);
    it =input_item();
  }

  return q;
}

queue * sottoCode(queue q)
{
  item it;
  int i;
  queue * sq = malloc(4*sizeof(queue));

  sq[0] = newQueue();
  sq[1] = newQueue();
  sq[2] = newQueue();
  sq[3] = newQueue();

  while(!emptyQueue(q))
  {
    it = dequeue(q);

    if(ascissa(it)<0)
    {
      if(ordinata(it)<0)
      {
        enqueue(it,sq[2]);
      }
      else
      {
        enqueue(it,sq[1]);
      }
    }
    else
    {
      if(ordinata(it)<0)
      {
        enqueue(it,sq[3]);
      }
      else
      {
        enqueue(it,sq[0]);
      }
    }
  }

  return sq;
}

float spezzata (queue q)
{
  float dist;
  item p1,p2;
  queue q2;

  q2 = newQueue();
  dist = 0;

  while(!emptyQueue(q))
  {
    p1=dequeue(q);
    enqueue(p1,q2);
  }

  p1=dequeue(q2);
  enqueue(p1,q);
  while(!emptyQueue(q2))
  {
    p2=dequeue(q2);
    enqueue(p2,q);

    dist += distanza(p1,p2);
    p1=p2;
  }

  return dist;
}

queue concatenazione(queue q1, queue q2)
{
  item it;
  queue q;

  q = newQueue();

  while(!emptyQueue(q1))
  {
    it = dequeue(q1);
    enqueue(it,q);
  }
  while(!emptyQueue(q2))
  {
    it = dequeue(q2);
    enqueue(it,q);
  }


  return q;
}

void schedulingProcessi(queue q,int cicliCPU)
{
  item it;
  int cpuBurst;
  outputStack(q);
  while(!emptyQueue(q))
  {
    it=dequeue(q);
    cpuBurst = ordinata(it)-cicliCPU;
    if(cpuBurst>0)
    {
      enqueue(creaItem(ascissa(it),cpuBurst),q);
    }

    outputStack(q);
  }
}
