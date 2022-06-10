#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"


struct node {
     item value;
     struct node *next;
};

struct node * UltimaOccorrenza(list l,item el);

list newList(void)
{
  return NULL;
}

int emptyList(list l)
{
  return l==NULL;
}

list consList(item val, list l)
{
  struct node* new;
  new = malloc(sizeof(*new));

  if(new)
  {
    new->value = val;
    new->next = l;
    l=new;
  }

  return l;

}

list tailList(list l)
{
  list temp;

  if(l)
  {
    temp = l->next;
  }
  else
  {
    temp = NULL;
  }

  return temp;
}

item getFirst (list l)
{
  item e;
  if(l)
  {
    e = l->value;
  }
  else
  {
    e = NULLITEM;
  }
}

int sizeList (list l)
{
  int n = 0;

  if(!l)
  {
    return n;
  }

  for(n = 0;!emptyList(l);n++)
  {
    l = tailList(l);
  }

  return n;

}

int posItem (list l, item val)
{
    if(emptyList(l))
    {
      return -1;
    }

    if(eq(getFirst(l),val))
    {
      return 0;
    }
    else
    {
      int ris = posItem(tailList(l),val);
      if(ris==-1)
      {
        return -1;
      }
      else
      {
        return ris + 1;
      }
    }

}

item getItem (list l, int pos)
{
  item e;
  int i;

  if(pos>=sizeList(l))
  {
    return NULLITEM;
  }


  for(i=0;i<pos && !emptyList(l);i++)
  {
    l = tailList(l);
  }

  if(!emptyList(l))
  {
    e=getFirst(l);
  }
  else
  {
    e = NULLITEM;
  }

  return e;
}

list reverseList (list l)
{
  list rev;
  item val;

  rev=newList();

  while(!emptyList(l))
  {
    val = getFirst(l);
    rev = consList(val,rev);
    l = tailList(l);
  }

  return rev ;

}

void outputList (list l)
{
  item val;
  while(!emptyList(l))
  {
    val = getFirst(l);
    output_item(val);
    printf("--->");
    l = tailList(l);
  }
  printf("nil\n");
}

list insertList(list l,int pos,item val)
{
  int i;
  list l1,prec=l;

  if(pos==0)
  {
    return consList(val,l);
  }

  for(i=0;i<pos-1&& prec; i++)
  {
    prec =prec->next;
  }

  if(!prec)
  {
    return l;
  }

  l1 = consList(val,prec->next);
  prec->next = l1;

  return l;
}

list removeList(list l,int pos)
{
  list l1,prec;
  int i;

  if(pos==0 && l)
  {
    l1=l;
    l=tailList(l);
    free(l1->value);
    free(l1);
  }
  else
  {
    prec = l;
    for(i=0;i<pos-1 && prec ;i++)
    {
      prec = prec->next;
    }

    if(prec && prec->next)
    {
      l1=prec->next;
      prec->next = l1->next;
      free(l1->value);
      free(l1);
    }
  }

  return l;
}



list cancDaItem(list l,item el)
{
  struct node * tmp;
  struct node * tmpForFree;

  tmp= UltimaOccorrenza(l,el);

  tmpForFree =tmp->next ;
  tmp->next = NULL;

  while(!emptyList(tmpForFree))
  {
    tmpForFree = removeList(tmpForFree,0);
  }

  return l;
}


list fondiDaItem(list l1,list l2,item el)
{
  struct node * tmp;
  struct node * tmp2;
  struct node * Ultimaoccl1;
  struct node * Ultimaoccl2;
  list newLista = newList();


  Ultimaoccl1 = UltimaOccorrenza(l1,el);
  Ultimaoccl2 = UltimaOccorrenza(l2,el);

  tmp = Ultimaoccl1->next;

  while(!emptyList(tmp))
  {
    tmp2 = Ultimaoccl2->next;
    while(!emptyList(tmp2))
    {
      if(eq(getFirst(tmp),getFirst(tmp2)))
      {
        newLista=consList(creaItem(getInt(getFirst(tmp))),newLista);
      }
      tmp2 = tmp2->next;
    }
    tmp = tmp->next;
  }

  return reverseList(newLista);

}


struct node * UltimaOccorrenza(list l,item el)
{
  struct node * tmp;
  struct node * Ultimaocc;

  tmp = l;
  Ultimaocc=NULL;

  while(!emptyList(tmp))
  {
    if(eq(getFirst(tmp),el))
    {
      Ultimaocc=tmp;
    }
    tmp = tmp->next;
  }

  return Ultimaocc;
}
