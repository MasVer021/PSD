#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

struct c_list {
  struct node *first;
  int size;
};

struct node {
  item value;
  struct node *next;
};

list newList(void)
{
  struct c_list *l;
  l=malloc(sizeof(*l));
  if(l)
  {
    l->first = NULL;
    l->size = 0;
  }
  return l;
}

int emptyList(list l)
{
  return l->size == 0;
}



static struct node* insertNode(struct node*l, int pos,item val)
{
  struct node *new,*prec;
  int i;

  prec = l;
  new = malloc(sizeof(*new));
  if(!new)
  {
    return NULL;
  }
  new->value = val;

  if(pos == 0)
  {
    new->next = l;
    return new;
  }

  for(i=0;i<pos-1 && prec!=NULL;i++)
  {
    prec = prec->next;
  }
  if(!prec)
  {
    free(new);
    return NULL;
  }
  new->next = prec->next;
  prec->next=new;
  return l;
}

int insertList(list l,int pos,item val)
{
  struct node*tmp = insertNode(l->first,pos,val);
  if(!tmp)
  {
    return 0;
  }
  l->first = tmp;
  l->size++;
  return 1;
}



static struct node *removeNode(struct node*l, int pos)
{
  struct node *l1,*prec;
  int i;

  if(pos == 0 && l)
  {
    l1 = l;
    l=l->next;
    free(l1->value);
    free(l1);
  }
  else
  {
    prec =l;
    for(i=0;i<pos-1 && prec!=NULL;i++)
    {
      prec = prec->next;
    }

    if(prec && prec->next)
    {
      l1 = prec->next;
      prec->next = l1->next;
      free(l1->value);
      free(l1);
    }
  }

  return l;
}

int removeList(list l,int pos)
{
  if(!l || l->first == NULL || l->size == 0 || pos>=sizeList(l))
  {
    return 0;
  }
  l->first = removeNode(l->first,pos);
  l->size--;
  return 1;
}

int sizeList (list l)
{
  return l->size;
}

item getItem (list l, int pos)
{
  struct node*l1 ;
  item e;
  int i;

  if(pos>=sizeList(l))
  {
    return NULLITEM;
  }

  l1=l->first;

  for(i=0;i<pos && l1;i++)
  {
    l1=l1->next;
  }

  if(l1)
  {
    e=l1->value;
  }
  else
  {
    e = NULLITEM;
  }

  return e;
}

list reverseList (list l)
{
  int i;
  list rev;
  int size =sizeList(l);

  rev=newList();

  for(i=0;i<size;i++)
  {
  insertList(rev,i,getItem(l,size-(i+1)));
  }

  return rev ;

}

void outputList (list l)
{
  int i;
  int size =sizeList(l);



  printf("size:%d---------->",l->size);


  for(i=0;i<size;i++)
  {
    output_item(getItem(l,i));
    printf("--->");
  }
  printf("nil");
}
