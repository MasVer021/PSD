#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include <math.h>

#include "item.h"


void PrintNodiInterv(BST T ,item a, item b);
int is2Pow(int x);
BST inputBilanciato(int *a , int lun);
int * nodiAltK(BST T,int k,int *i);
void ricercaNodiK(BST T,int k,int lv,int* a,int *i);
int isMediano (BST T, item U);
BST SRCnode(BST T, item U);
int contanodi(BST T);

int contaArchi(BST T ,item U);
int numeroDiArchi(BST T,item X,item Y);

BST LCA(BST T,item X,item Y);


int main(void)
{
  int i,j;
  item a [] = {15,10,25,8,12,20,30,6,9,18,22};
  BST T = newBST();

  for(i=0;i<sizeof(a)/sizeof(int);i++)
  {
    T = insert(T,a[i]);
  }


//  T = inputBilanciato(a,sizeof(a)/sizeof(int));
  //PrintNodiInterv(T ,10,30);

  //int *k = nodiAltK(T,5,&i);

//  printf("%d\n",isMediano(T,12));

/* for(j=0;j<i;j++)
  {
    output_item(k[j]);
  }*/



  //printf("%d",numeroDiArchi(T,6,15));

  //output_item(getItem(LCA(T,30,8)));

  return 0;
}


BST LCA(BST T,item X,item Y)
{
  if(Y<X)
  {
    return LCA(T, Y, X);
  }

  if(maggiore(getItem(T),Y))
  {
    return LCA(figlioSX(T), X, Y);
  }

  if(minore(getItem(T),X))
  {
    return LCA(figlioDX(T), X, Y);
  }

  return T;
}

int contaArchi(BST T ,item U)
{
  if(maggiore(getItem(T),U))
  {
    return 1+ contaArchi(figlioSX(T) ,U);
  }

  if(minore(getItem(T),U))
  {
    return 1+ contaArchi(figlioDX(T) ,U);
  }

  return 0;
}

int numeroDiArchi(BST T,item X,item Y)
{

  if(maggiore(getItem(T),Y))
  {
    return numeroDiArchi(figlioSX(T), X, Y);
  }

  if(minore(getItem(T),X))
    return numeroDiArchi(figlioDX(T), X, Y);

  return contaArchi(T,X)+contaArchi(T,Y);
}

int contanodi(BST T)
{
  if(!T)
  {
    return 0;
  }
  return  1 + contanodi(figlioSX(T)) + contanodi(figlioDX(T));

}

BST SRCnode(BST T, item U)
{
  if(eq(getItem(T),U))
  {
      return T;
  }

  else if(minore(getItem(T),U))
  {
    return SRCnode(figlioDX(T),U);
  }
  else
  {
    return SRCnode(figlioSX(T),U);
  }
}

int isMediano (BST T, item U)
{
  BST RU;


  if(contains(T,U))
  {
    RU = SRCnode(T,U);
    return contanodi(figlioDX(RU)) == contanodi(figlioSX(RU));
  }

  return 0;
}



BST inputBilanciato(int *a , int lun)
{
  int i;
  BST T = newBST();

  if(!is2Pow(lun+1))
  {
    return NULL;
  }

  for(i=0;i<lun;i++)
  {
    T = insert(T,a[i]);
  }

  return T;
}


void PrintNodiInterv(BST T ,item a, item b)
{
  if(!T)
  {
    return;
  }

  if( getItem(T)>a)
  {
    PrintNodiInterv(figlioSX(T),a,b);
  }

  if(getItem(T)>=a && getItem(T)<=b)
  {
    output_item(getItem(T));
    printf("-");
  }

  if(getItem(T)<b)
  {
      PrintNodiInterv(figlioDX(T),a,b);
  }
}

int is2Pow(int x)
{
  if(x%2 == 1)
  {
    return 0;
  }

  if(x == 1)
  {
    return 1;
  }

  return is2Pow(x/2);
}


int * nodiAltK(BST T,int k,int *i)
{
  int* a = malloc(pow(2,k)*sizeof(int));

  *i=0;
  ricercaNodiK(T,k,0,a,i);

  a = realloc(a,(*i)*sizeof(int));

  return a;

}
void ricercaNodiK(BST T,int k,int lv,int* a,int *i)
{
  if(!T)
  {
    return ;
  }

  if(k==lv)
  {
    a[(*i)++] = getItem(T);
  }

  if(k>lv)
  {
    ricercaNodiK(figlioSX(T),k,lv+1,a,i);
    ricercaNodiK(figlioDX(T),k,lv+1,a,i);
  }
}
