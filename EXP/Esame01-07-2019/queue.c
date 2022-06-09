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



void cancFinoItem(item val, queue q)
{


  while(!eq(q->head->value,val) && !emptyQueue(q))
  {
    dequeue(q);
  }
}

queue fondiDaItem(item el, queue q1,queue q2)
{
  struct node *tmp;
  tmp = malloc (sizeof(*tmp));

  struct node *tmp2;
  tmp2 = malloc (sizeof(*tmp2));


  queue q3 = newQueue();

  if(tmp && tmp2 && q3)
  {
    cancFinoItem(el,q1);
    cancFinoItem(el,q2);

    if(!emptyQueue(q1))
    {
      dequeue(q1);
    }
    if(!emptyQueue(q2))
    {
      dequeue(q2);
    }


    tmp =q1->head;

    while(tmp)
    {
      tmp2 =q2->head;
      while(tmp2)
      {
        if(eq(tmp->value,tmp2->value))
        {
          enqueue(tmp->value,q3);
          break;
        }
        tmp2 = tmp2->next;
      }
      tmp = tmp->next;
    }
}
  return q3;
  free(tmp);
}
