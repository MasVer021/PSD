#include <stdio.h>
#include <stdlib.h>
#include "Btree.h"

#include "item.h"

#define NODO3 consBtree(3,NULL,NULL)
#define NODO6 consBtree(6,NULL,NULL)
#define NODO5 consBtree(5,NODO3,NODO6)

#define NODO10 consBtree(10,NODO5,NODO15)
#define NODO15 consBtree(15,NULL,NULL)
#define NODO20 consBtree(20,NODO10,NODO30)

#define NODO30 consBtree(30,NODO25,NODO40)
#define NODO25 consBtree(25,NULL,NULL)
#define NODO40 consBtree(40,NODO35,NULL)

#define NODO35 consBtree(35,NULL,NULL)


int isBST(Btree T);

int main(void)
{
  Btree bt = NODO20;
  outputTree(bt);
  printf("è un albero binario di ricerca :%d\n",isBST(bt));




  return 0;
}


int isBST(Btree T)
{
  if(!T)
  {
    return 1;
  }

  if(figlioDX(T) && !minore(getItem(getRoot(T)),getItem(getRoot(figlioDX(T)))) )
  {
    return 0;
  }

  if(figlioSX(T) && minore(getItem(getRoot(T)),getItem(getRoot(figlioSX(T)))) )
  {
    return 0;
  }

  return isBST(figlioSX(T)) && isBST(figlioDX(T));

}
