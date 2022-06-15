#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "Btree.h"
#include "queue.h"


struct node{
  item value;
  struct node* left;
  struct node* right;
};


void setItem(node *N, item el);

item getItem(node *N)
{
  if (!N)
  {
    return 0;
  }

  return N->value;
}

void setItem(node *N, item el)
{
  if (!N)
  {
    return;
  }

  N->value = el;
}

Btree newBtree(void)
{
  return NULL;
}

int emptyBtree(Btree T)
{
  return T == NULL;
}

node * getRoot(Btree T)
{
  return T;
}

Btree consBtree(item val, Btree sx, Btree dx)
{
  struct node *nuovo;
  nuovo = malloc (sizeof(struct node));

  if (nuovo)
  {
    setItem(nuovo, val);
    nuovo->left = sx;
    nuovo->right = dx;
  }

  return nuovo;
}
Btree figlioSX(Btree T)
{
  if (T)
  {
    return  T->left;
  }
  else
  {
    return NULL;
  }

}

Btree figlioDX(Btree T)
{
  if (T != NULL)
  {
     return  T->right;
  }
  else
  {
    return NULL;
  }
}

void creafoglia(Btree T , node * foglia,int lato)
{
  if(lato == 0)
  {
    T->left = foglia;
  }
  else
  {
      T->right = foglia;
  }
}

static void ricercaNodiK(Btree T,int k,char * s)
{
  if(!T)
  {
    printf("%s ",s);
    return ;
  }

  if(k==0)
  {
    output_item(getItem(T));
    printf("%s",s);
  }

  if(k>0)
  {
    ricercaNodiK(figlioSX(T),k-1,s);
    ricercaNodiK(figlioDX(T),k-1,s);
  }
}

static int altezza(Btree T)
{
  if(!T)
  {
    return 0;
  }

  if(altezza(figlioDX(T)) > altezza(figlioSX(T)))
  {
    return 1+altezza(figlioDX(T));
  }

  return 1+altezza(figlioSX(T));
}

void outputTree(Btree T)
{

  int i = altezza(T);
  char *s = malloc(pow(2,i)-1);

  for(int j=0;j<=i;j++)
  {
    for(int x=0;x<pow(2,i-j-1)-1;x++)
    {
      printf("  ");
    }
    *s='\0';
    for(int x=0;x<pow(2,i-j)-1;x++)
    {
      strcat(s,"  ");
    }

    ricercaNodiK(T,j,s);
    printf("\n" );
  }

}
