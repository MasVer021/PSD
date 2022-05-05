#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

struct node {
     item value;
     struct node *next;
};

struct c_queue {
     struct node *head,*tail;
     int numel;
};

queue newQueue(void)
{
     struct c_queue *q;
     q = malloc (sizeof(struct c_queue));

     if (!q)
     {
       return NULL;
     }

     q->numel = 0;
     q->head = NULL;
     q->tail = NULL;
     return q;
}

int emptyQueue(queue q)
{
     if (!q)
     {
       return -1;
     }

     return q->numel == 0;
}

int enqueue(item val, queue q)
{
    if (!q)
    {
      return -1;
    }

    struct node *nuovo;
    nuovo = malloc (sizeof(*nuovo));

    if (!nuovo)
    {
      return 0;
    }

    nuovo->value = val;
    nuovo->next = NULL;

    if(q->head==NULL)
    {
       q->head = nuovo;
    }
    else
    {
       q->tail->next= nuovo;
    }

    q->tail = nuovo;
    (q->numel)++;

    return 1;
}

item dequeue(queue q)
{
      if (!q || q->numel == 0 )
      {
        return NULLITEM;
      }

      item result = q->head->value;

      struct node *temp = q->head;

      q->head = q->head->next;
      free(temp);

      if(q->head==NULL)
      {
        q->tail=NULL;
      }

      (q->numel)--;

      return result;
}


queue reverseQueue(queue q)
{

  if(!q)
  {
    return NULL;
  }

  queue q1,q2;
  item a,b;

  q1 = newQueue();
  q2 = clonaQueue(q);

  enqueue(NULLITEM,q2);

  a=dequeue(q2);

  while(!emptyQueue(q2))
  {

    b = dequeue(q2);

    if(b!= NULLITEM)
    {
      enqueue(a,q2);
      a=b;
    }
    else
    {
      enqueue(b,q2);
      enqueue(a,q1);
      a=dequeue(q2);
    }
  }

  return q1;

}


void outputStack(queue q)
{
  struct node* pn;

  pn = q->head;
  printf("head --->");


  while(pn)
  {
    output_item(pn->value);
    printf("--->");
    pn=pn->next;


  }

  printf("tail\n" );
}

queue clonaQueue(queue q)
{
  if(!q)
  {
    return NULL;
  }
  queue q1;
  item it;

  q1 = newQueue();

  enqueue(NULLITEM,q);
  it = dequeue(q);

  while(it!= NULLITEM)
  {
    enqueue(it,q);
    enqueue(creaItem(ascissa(it),ordinata(it)),q1);

    it = dequeue(q);
  }

  return q1;
}
