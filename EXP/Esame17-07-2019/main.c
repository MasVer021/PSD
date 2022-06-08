#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "item.h"
#include "PQueue.h"





int main(void)
{
  PQueue PQ = newPQ();
  insert(PQ,newItem(1,11));
  insert(PQ,newItem(2,12));
  insert(PQ,newItem(3,13));
  insert(PQ,newItem(4,14));
  insert(PQ,newItem(6,16));
  insert(PQ,newItem(5,15));

  PrintPQ(PQ);
//  aumentaPrior(PQ);
//  PrintPQ(PQ);

  list l = estraiPriorK(PQ,3);
  outputList(l);







  return 0;
}
