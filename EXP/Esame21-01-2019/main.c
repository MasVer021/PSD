#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

#include "item.h"


int main(void)
{
  int i;


item a [] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
BST T = newBST();

/*for(i=0;i<sizeof(a)/sizeof(int);i++)
{
  T = insert(T,a[i]);
}*/

  constrAVL(&T,a,sizeof(a)/sizeof(int));
  outputBST(T);

  return 0;
}
