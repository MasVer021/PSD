#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"
#include "utile.h"

int contCoppDisMin(list l,float dis);
item* coppPuntDisMax(list l);
void riordina(list* l, char coordinata,char criterio);
list sottoLista(list* l,int m,int n);
list inserisci_lista(list l,list k,int m);
list zigzag(list *l);
void disegnaGrafico(list* l);

int main (int argc, char *argv[]){
  int i;
  list l = newList();
  list k = newList();


    l=consList(creaItem(1,2),l);
    l=consList(creaItem(2,4),l);
    l=consList(creaItem(1,3),l);
    l=consList(creaItem(3,3),l);
    l=consList(creaItem(2,1),l);
    l=consList(creaItem(5,3),l);
    l=consList(creaItem(6,5),l);
    l=consList(creaItem(6,2),l);
    l=consList(creaItem(3,4),l);
    l=consList(creaItem(7,2),l);
    l=consList(creaItem(10,4),l);
    l=consList(creaItem(3,2),l);
    l=consList(creaItem(5,6),l);
    l=consList(creaItem(12,2),l);
    l=consList(creaItem(11,4),l);

    k=consList(creaItem(1,1),k);
    k=consList(creaItem(2,2),k);


    /*printf("ordinata per ascissa decrescente\n");
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
    outputList(l);*/

    /*output_item(coppPuntDisMax(l)[0]);
    output_item(coppPuntDisMax(l)[1]);*/

    /*list sub = sottoLista(l,1,2);
    outputList(sub);
    outputList(l);*/

  /*  printf("l\n");
    outputList(l);
    printf("k\n");
    outputList(k);
    l=inserisci_lista(l,k,2);*/

    //zigzag(&l);
    disegnaGrafico(&l);
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
    ord = consList(creaItem(ascissa(getItem(*l,index)),ordinata(getItem(*l,index))), ord);
    *l = removeList(*l,index);

  }
  if(criterio=='d')
  {
    ord = reverseList(ord);
  }
    *l=ord;
}

list sottoLista(list* l,int m,int n)
{
  int i;
  list sublist= newList();


  for(i=m;i<=n;i++)
  {
    sublist=consList(creaItem(ascissa(getItem(*l,i)),ordinata(getItem(*l,i))), sublist);
  }
  for(i=m;i<=n;i++)
  {
    *l = removeList(*l,m);
  }


  return reverseList(sublist);
}

list inserisci_lista(list l,list k,int m)
{
  int i;
  //outputList(l);

  for(i=0;i<sizeList(k);i++)
  {
    l=insertList(l,m+i,getItem(k,i));
  }

  return l;
}

list zigzag(list* l)
{
  list sub,zigZagList;
  riordina(l,'a','c');
  item it1,it2;
  int i,index;

  zigZagList=newList();
  index =0;

  for(i=0;i<sizeList(*l);i++)
  {
    it1=getItem(*l,i);
    it2=getItem(*l,i+1);

    if(it2 && ascissa(it1)==ascissa(it2))
    {
      index ++;
    }
    else
    {
      sub = sottoLista(l,i-index,i);
      riordina(&sub,'o','c');
      zigZagList=inserisci_lista(zigZagList,sub,sizeList(zigZagList));
      i=-1;
      index=0;
    }
  }
  outputList(zigZagList);
  return zigZagList;
}

void disegnaGrafico(list* l)
{
  list sub,grafList;
  riordina(l,'o','d');
  item it1,it2;
  int i,j,x,index;

  grafList=newList();
  index =0;

  for(i=0;i<sizeList(*l);i++)
  {
    it1=getItem(*l,i);
    it2=getItem(*l,i+1);

    if(it2 && ordinata(it1)==ordinata(it2))
    {
      index ++;
    }
    else
    {
      sub = sottoLista(l,i-index,i);
      riordina(&sub,'a','c');
      grafList=inserisci_lista(grafList,sub,sizeList(grafList));
      i=-1;
      index=0;
    }
  }

  j=0;
  for(i=0;i<sizeList(grafList);i++)
  {
    //printf("%g//%g",ordinata(getItem(grafList,i-1)),ordinata(getItem(grafList,i)));
    if(i-1>0 && ordinata(getItem(grafList,i-1))==ordinata(getItem(grafList,i)))
    {
      j=x;
    }
    else
    {
      j=0;
    }


    while(j<ascissa(getItem(grafList,i))*3)
    {
      printf("_");
      j++;

    }
    x=j+1;
    printf("o");
    for(j=0;i<sizeList(grafList)-1 && j<ordinata(getItem(grafList,i))-ordinata(getItem(grafList,i+1));j++)
    {
      printf("\n");
    }

  }

  printf("\n");

}
