#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

#include "item.h"


int main(void)
{
  int i;


item a [] = {1,2,3,4,5,6,7,8,9,10};
BST T = newBST();

/*for(i=0;i<sizeof(a)/sizeof(int);i++)
{
  T = insert(T,a[i]);
}*/

  constrAVL(&T,a,sizeof(a)/sizeof(int));
  outputBST(T);

  return 0;
}
