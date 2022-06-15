#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "item.h"


int eq(item a, item b)
{
   return a==b ;
}


void input_item(item * it)
{
  printf("inserisci intero: ");
  scanf("%d",it);
}


void output_item(item it)
{
    printf("%2d",it);
}
