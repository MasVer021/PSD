#include "Btree.h"
#include "queue.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "stack.h"

#define SIZE 100
char* itoa(int num, char* buffer, int base);
void valutaEspressione(Btree T,stack s);
int valuta(Btree T);


int main(void)
{

  Btree bt = newBtree();
  bt = consBtree("-",consBtree("*",consBtree("+",consBtree("5",NULL,NULL),consBtree("20",NULL,NULL)),consBtree("2",NULL,NULL)),consBtree("4",NULL,NULL));


  outputTree(bt);



  printf("il valore dell'espressione è :%d\n", valuta(bt));


  //insertNode(bt,'5');
  return 0;
}





void valutaEspressione(Btree T, stack s)
{
  if(!T)
  {
    return;
  }
  valutaEspressione(figlioSX(T),s);
  valutaEspressione(figlioDX(T),s);
  push(getItem(T),s);

}

int valuta(Btree T)
{

  stack s = newStack();
  valutaEspressione(T,s);
  reverseStack(s);

  int i;

  char *a,*b,*o;

  char r [100];
  printf("\n" );

  while(!emptyStack(s))
  {

      a = top(s);
      pop(s);
      b = top(s);
      pop(s);
      o = top(s);
      pop(s);


      printf("%s%s%s",a,o,b);
      switch (*o) {
        case'+' :
        itoa(atoi(a) + atoi(b),r,10);

          break;
        case'-' :
          itoa(atoi(a) - atoi(b),r,10);

          break;
        case'*' :
          itoa(atoi(a) * atoi(b),r,10);

          break;
        case'/' :
          itoa(atoi(a) / atoi(b),r,10);

          break;
      }

      printf("=%s\n",r);
      if(!emptyStack(s))  push(r,s);
      printf("\n" );
  }

  return atoi(r);
}



char* itoa(int num, char* buffer, int base)
{
  int current = 0;
  if (num == 0)
  {
    buffer[current++] = '0';
    buffer[current] = '\0';
    return buffer;
  }
  int num_digits = 0;
  if (num < 0)
  {
    if (base == 10)
    {
      num_digits ++;
      buffer[current] = '-';
      current ++;
      num *= -1;
    }
    else
      return NULL;
  }
  num_digits += (int)floor(log(num) / log(base)) + 1;

  while (current < num_digits)
  {
    int base_val = (int) pow(base, num_digits-1-current);
    int num_val = num / base_val;
    char value = num_val + '0';
    buffer[current] = value;
    current ++;
    num -= base_val * num_val;
  }
  buffer[current] = '\0';
  return buffer;
}
