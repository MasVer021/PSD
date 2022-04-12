#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "item.h"


struct puntoitem{
  int n;
};

int eq(item a, item b)
{
   return a->n==b->n ;
}

item creaItem(int x)
{

  item p = malloc(sizeof(*p));

  if(p)
  {
    p->n=x;
  }

  return p;
}

item input_item()
{

  int x;
  printf("inserisci intero: ");
  scanf("%d",&x);

  return creaItem(x);
}

int getInt(item it)
{
  return it->n;
}
void output_item(item it)
{
    printf("%d",it->n);
}
