#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"
#include "utile.h"

int contCoppDisMin(list l,float dis);
item* coppPuntDisMax(list l);
void riordina(list* l, char coordinata,char criterio);

int main (int argc, char *argv[]){
  int i;
  list l = newList();


    l=consList(creaItem(1,6),l);
    l=consList(creaItem(3,8),l);
    l=consList(creaItem(5,5),l);
    l=consList(creaItem(8,-6.7),l);
    l=consList(creaItem(-5,4),l);
    l=consList(creaItem(8.2,29),l);

    printf("non ordinata\n");
    outputList(l);
    printf("ordinata per ascissa decrescente\n");
    riordina(&l,'a','d');
    outputList(l);
    printf("ordinata per ordinata decrescente\n");
    riordina(&l,'o','d');
    outputList(l);
    printf("ordinata per ascissa crescente\n");
    riordina(&l,'a','c');
    outputList(l);
    printf("ordinata per ordinata crescente\n");
    riordina(&l,'o','c');
    outputList(l);
	return 0;
}

int contCoppDisMin(list l,float dis)
{
  int i,j,count;
  int size = sizeList(l);
  item a,b;

  count =0;

  for(i=0;i<size-1;i++)
  {
    a=getItem(l,i);
    for(j=i+1;j<size;j++)
    {
      b=getItem(l,j);
      if(distanza(a,b)<dis)
      {
        count++;
      }
    }
  }

  return count;
}

item* coppPuntDisMax(list l)
{
  int i,j,dis;
  int size = sizeList(l);
  item a,b;
  item* max;

  max = xmalloc(sizeof(item)*2);


  dis = 0;

  for(i=0;i<size-1;i++)
  {
    a=getItem(l,i);
    for(j=i+1;j<size;j++)
    {
      b=getItem(l,j);
      if(distanza(a,b)>dis)
      {
        dis = distanza(a,b);
        max[0]=a;
        max[1]=b;
      }
    }
  }

  return max;
}

void riordina(list* l, char coordinata,char criterio)
{
  int i;
  list ord = newList();


  float var;
  int index;

  while(!emptyList(*l)){
    if(coordinata=='a')
    {
      var = ascissa(getItem(*l,0));
    }
    else if(coordinata=='o')
    {
      var = ordinata(getItem(*l,0));
    }
    index = 0;
    for(i=0;i<sizeList(*l);i++)
    {
      if(coordinata=='a')
      {
        if(var<ascissa(getItem(*l,i)))
        {
          var = ascissa(getItem(*l,i));
          index = i;
        }
      }
      else if(coordinata=='o')
      {
        if(var<ordinata(getItem(*l,i)))
        {
          var = ordinata(getItem(*l,i));
          index = i;
        }
      }

    }
    ord = consList(getItem(*l,index), ord);
    *l = removeList(*l,index);

  }
  outputList(*l);
  if(criterio=='d')
  {
    ord = reverseList(ord);
  }
    *l=ord;
}
