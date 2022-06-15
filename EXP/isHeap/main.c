#include "Btree.h"


#include <stdio.h>
#include <stdlib.h>



#define NODO9 consBtree(9,NULL,NULL)
#define NODO8 consBtree(8,NULL,NULL)
#define NODO4 consBtree(4,NODO8,NODO20)
#define NODO5 consBtree(5,NODO20,NULL)
#define NODO2 consBtree(2,NODO4,NODO5)

#define NODO1 consBtree(1,NODO2,NODO3)
#define NODO3 consBtree(3,NODO7,NODO6)
#define NODO7 consBtree(7,NULL,NULL)
#define NODO6 consBtree(6,NULL,NULL)
#define NODO20 consBtree(20,NULL,NULL)

#define NODO35 consBtree(35,NULL,NULL)

int isHeap(Btree T);
int HBT(Btree T);
int PB(Btree T);

int main(void)
{
     Btree T = newBtree();

    T=NODO1;
    outputTree(T);
  /*  outputTree(figlioSX(T));
    printf("%d\n",PB(figlioSX(T)));*/

    printf("%d",isHeap(T));
    return 0;
}



int isHeap(Btree T)
{
    if(!figlioSX(T) && !figlioDX(T))
    {
        return 1;
    }

    if(!figlioSX(T) && figlioDX(T))
    {
        return 0;
    }

    if(getItem(T)<=getItem(figlioSX(T)) && (getItem(T)<=getItem(figlioDX(T)) || !figlioDX(T))) // IN QUESTO CASO IL CONTROLLO RIGUARDA I MIN HEAP in quanto <=
    {
        if((PB(figlioSX(T)) && HBT(figlioSX(T))==HBT(figlioDX(T))) || HBT(figlioSX(T))==(HBT(figlioDX(T))+1))
        {
            return isHeap(figlioSX(T)) && isHeap(figlioDX(T));
        }
    }

    return 0;


}


int HBT(Btree T) // calcola altezza albero
{
    if(!T)
    {
        return 0;
    }

    if(HBT(figlioDX(T))>HBT(figlioSX(T)))
    {
        return 1+ HBT(figlioDX(T));
    }


     return 1+HBT(figlioSX(T));
}


int PB(Btree T) // calcola se l'albero è perfettamente bilanciato
{
  if(!T)
  {
    return 1;
  }

  if((!figlioDX(T) && figlioSX(T)) || (figlioDX(T) && !figlioSX(T)) || HBT(figlioDX(T)) != HBT(figlioSX(T)))
  {
    return 0;
  }

  return PB(figlioSX(T)) && PB(figlioDX(T));
}
