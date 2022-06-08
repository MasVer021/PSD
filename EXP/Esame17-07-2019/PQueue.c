#include <stdio.h>
#include <stdlib.h>
#include "PQueue.h"
#define MAXPQ 50

struct c_PQ {
     item vet[MAXPQ];
     int numel;
};

static void scendi (PQueue q);
static void sali (PQueue q);

PQueue newPQ(void)
{
     PQueue q;
     q = malloc (sizeof(struct c_PQ));
     if (q == NULL) return NULL;
     q->numel = 0;
     return q;
}

int emptyPQ(PQueue q)
{
     if (!q)  return 1;
     return q->numel == 0;
}


item getMax(PQueue q)
{
    if(!emptyPQ(q))
    {
       return q->vet[1];
    }

    return NULLITEM;
}

int deleteMax(PQueue q)
{
     if (!q || q->numel==0) return 0;   // CODA VUOTA

     q->vet[1] = q->vet[q->numel];  //SPOSTO L’ULTIMO ELEMENTO
     q->numel --;                               // IN POSIZIONE 1

     scendi(q);      // RIAGGIUSTO LO HEAP SCENDENDO

     return 1;
}

static void scendi (PQueue q)
{
    item temp;
    int n=q->numel, i=1, pos;

    while (1)
    {
       if (2*i+1 <= n)               // IL NODO CORRENTE HA 2 FIGLI
                  pos =  (isMaxKey(q->vet[i*2],q->vet[i*2+1]))  ?   i*2  :   i*2+1;

       else  if (2*i <= n)          // IL NODO CORRENTE HA 1 FIGLIO
                  pos = 2*i;
       else  break;                  // IL NODO CORRENTE NON HA FIGLI

       if (isMaxKey(q->vet[pos],q->vet[i]))     // SCAMBIO LE CHIAVI E PROSEGUO
       {
             temp = q->vet[i];
             q->vet[i] = q->vet[pos];
             q->vet[pos] = temp;
             i = pos;
       }
       else
           break;   // NON CI SONO PIU’ SCAMBI DA FARE, MI FERMO
     }
}
int insert (PQueue q, item ele)
{

     if (!q || q->numel==MAXPQ) return 0; // CODA PIENA

     q->numel++;
     q->vet[q->numel] = ele;   // INSERISCI IN ULTIMA POSIZIONE

     sali(q);     // AGGIUSTA LO HEAP RISALENDO

     return 1;
}

static void sali (PQueue q)
{
    item temp ;
    int pos=q->numel, i=pos/2;

    while (pos>1)
    {

       if (isMaxKey(q->vet[pos],q->vet[i]))
       {
             temp = q->vet[i];
             q->vet[i] = q->vet[pos];
             q->vet[pos] = temp;
             pos = i;
             i = pos/2;
       }

       else
             break;
     }
}



void aumentaPrior(PQueue q)
{
  int i;

  for(i=q->numel;i>1;i--)
  {
    setKey(q->vet[i],getKey(q->vet[i/2]));
  }
}


void PrintPQ(PQueue q)
{
  int i;

  for(i=1;i<q->numel;i++)
  {
    printItem(q->vet[i]);
    printf("\n");
  }
}



list estraiPriorK(PQueue q,int k)
{

  list l = newList();
  int i,flag;

  flag =0;

  if(getKey(q->vet[1])>=k)
  {
    insertList(l,0,q->vet[1]);
    flag=1;
  }

  for(i = 2 ; i<q->numel && flag ;i*=2)
  {
    flag=0;

    if(getKey(q->vet[i])>=k)
    {
      insertList(l,0,q->vet[i]);
      flag=1;
    }
    
    if(getKey(q->vet[i+1])>=k)
    {
      insertList(l,0,q->vet[i+1]);
      flag=1;
    }
  }
  return l;
}
