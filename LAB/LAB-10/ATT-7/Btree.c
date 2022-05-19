#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Btree.h"
#include "queue.h"


struct node{
  item value;
  struct node* left;
  struct node* right;
};


void setItem(node *N, item el);

item getItem(node *N)
{
  if (!N)
  {
    return 0;
  }

  return N->value;
}

void setItem(node *N, item el)
{
  if (!N)
  {
    return;
  }

  N->value = el;
}

Btree newBtree(void)
{
  return NULL;
}

int emptyBtree(Btree T)
{
  return T == NULL;
}

node * getRoot(Btree T)
{
  return T;
}

Btree consBtree(item val, Btree sx, Btree dx)
{
  struct node *nuovo;
  nuovo = malloc (sizeof(struct node));

  if (nuovo)
  {
    setItem(nuovo, val);
    nuovo->left = sx;
    nuovo->right = dx;
  }

  return nuovo;
}
Btree figlioSX(Btree T)
{
  if (T)
  {
    return  T->left;
  }
  else
  {
    return NULL;
  }

}

Btree figlioDX(Btree T)
{
  if (T != NULL)
  {
     return  T->right;
  }
  else
  {
    return NULL;
  }
}

void creafoglia(Btree T , node * foglia,int lato)
{
  if(lato = 0)
  {
    T->left = foglia;
  }
  else
  {
      T->right = foglia;
  }
}

void outputTree(Btree T)
{

  int n;
  Btree nd = newBtree();
  queue q = newQueue();

  void * spazio = malloc(sizeof(int));

  if(T)
  {
    enqueue(T,q);
  }


  n=0;
  while(!emptyQueue(q))
  {

    nd= (Btree)dequeue(q);

    if(!n)
    {
      n=1;
      enqueue(NULL,q);
    }

    if(nd == spazio)
    {
      //printf("NF");
      continue;
    }

    if(!nd)
    {
      printf("\n");
      n=0;
      continue;
    }

    output_item(nd->value);

    if(figlioSX(nd))
    {
      enqueue(figlioSX(nd),q);
    }
    else
    {
      enqueue(spazio,q);
    }

    if(figlioDX(nd))
    {
      enqueue(figlioDX(nd),q);
    }
    else
    {
      enqueue(spazio,q);
    }


  }

}
