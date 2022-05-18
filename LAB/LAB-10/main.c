#include "Btree.h"
#include "queue.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 100

Btree inputBtree(int *a , int lung,int lv);
int * fileToArray(char *nf ,int* lun);
int contafoglie(Btree T);
Btree speculare(Btree T);
int eqBTree(Btree T1, Btree T2);
int max(Btree T);
int min(Btree T);
void insertNode(Btree T,item it);


int main(void)
{
  int  lunga,numeroFoglie;
  int *a = fileToArray("int.txt",&lunga);
  Btree bt = newBtree();
  bt = inputBtree(a,lunga,0);
  outputTree(bt);
  //printf("%d\n",contafoglie(bt));

/*  outputTree(bt);
  printf("max: %d\n",max(bt));
  printf("min: %d\n",min(bt));
  bt = speculare(bt);
  outputTree(bt);
  printf("max: %d\n",max(bt));
  printf("min: %d\n",min(bt));
  //min(bt);


  int a1[] = {1,2,3,4,5,6,7,8,9};

  int a2[] = {1,2,3,4,5,6,7,8,9};
  Btree bt1 = inputBtree(a1,9,0);
  Btree bt2 = inputBtree(a2,9,0);
//  printf("%d\n",eqBTree(bt1,bt2 ) );
//  outputTree(bt);*/

  printf("Aggiungo 3 \n" );
  insertNode(bt,20);
  outputTree(bt);
  return 0;
}

int * fileToArray(char *nf ,int* lun)
{

  int j;
  int i;

  j=0;
  FILE * fp = fopen(nf,"r");
  if(fp)
  {
    while(fscanf(fp,"%d\n",&i)==1)
    {
      j++;
    }
    fclose(fp);
  }

  int *a = malloc(j*sizeof(int));

  fp = fopen(nf,"r");
  if(fp)
  {
    for(i=0;i<j;i++)
    {
      fscanf(fp,"%d\n",&a[i]);

    }
    fclose(fp);
  }

  *lun =j;
  return a;

}

Btree inputBtree(int *a , int lung,int lv)
{
  if(lung<=0)
  {
    return NULL;
  }

  return consBtree(*a,inputBtree(a+(int)pow(2,lv),lung-pow(2,lv),lv+1),inputBtree(a+(int)pow(2,lv+1),lung-pow(2,lv+1),lv+1));
}

int contafoglie(Btree T)
{
  if(!T)
  {
    return 0;
  }

  if(!figlioSX(T) && ! figlioSX(T))
  {
    return 1;
  }

  return contafoglie(figlioSX(T)) + contafoglie(figlioDX(T));
}

int max(Btree T)
{
  if(!T)
  {
    return INT_MIN;
  }

  if(getItem(getRoot(T))>max(figlioSX(T)) && getItem(getRoot(T))>max(figlioDX(T)))
  {
    return getItem(getRoot(T));
  }
  else if(max(figlioSX(T))>max(figlioDX(T)))
  {
    return max(figlioSX(T));
  }
  else
  {
    return max(figlioDX(T));
  }
}

int min(Btree T)
{
  //  printf("%d\n",getItem(getRoot(T) ));
  if(!T)
  {
    return INT_MAX;
  }

  if(getItem(getRoot(T))<min(figlioSX(T)) && getItem(getRoot(T))<min(figlioDX(T)))
  {
    return getItem(getRoot(T));
  }
  else if(min(figlioSX(T))<min(figlioDX(T)))
  {
    return min(figlioSX(T));
  }
  else
  {
    return min(figlioDX(T));
  }

}

Btree speculare(Btree T)
{
  if(!T)
  {
    return NULL;
  }

  return consBtree(getItem(getRoot(T)),speculare(figlioDX(T)),speculare(figlioSX(T)));
}


int eqBTree(Btree T1, Btree T2){


    if(!T1 && !T2)
    {
      return 1;
    }

    if (getItem(getRoot(T1)) != getItem(getRoot(T2)))
    {
      return 0;
    }
    else if (eqBTree(figlioSX(T1),figlioSX(T2)) && eqBTree(figlioDX(T1),figlioDX(T2)))
    {
      return 1;
    }
}




void insertNode(Btree T,item it)
{

    int i=0;
    Btree nd = newBtree();
    Btree daInserire = newBtree();
    queue q = newQueue();


    if(T)
    {
      enqueue(T,q);
    }


    do
    {

      nd= (Btree)dequeue(q);


      if(figlioSX(nd))
      {
        enqueue(figlioSX(nd),q);
      }

      if(figlioDX(nd))
      {
        enqueue(figlioDX(nd),q);
      }

      daInserire = nd;
    }while(figlioDX(nd) && figlioSX(nd));





    if(!figlioDX(daInserire))
    {

      creafoglia(daInserire,consBtree(it,NULL,NULL),1);
    }
    else
    {

      creafoglia(daInserire,consBtree(it,NULL,NULL),0);
    }



}
