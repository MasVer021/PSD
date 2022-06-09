#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "item.h"


int eq(item a, item b)
{
  if(a && b) return *a==*b;

  return 0;
}
item creaItem(int a)
{
  int * p = malloc(sizeof(int)*1);

  *p=a;

  return p;
}

void output_item(item it)
{
  printf("%d",*it);
}
