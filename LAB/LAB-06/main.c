#include <stdio.h>
#include "list.h"

int cercaElemento(item it,list l);
item cercaPosizione(int pos,list l);
list switchACoppie(list l);
list delMidEle(list l);

int main(void)
{
  list l;
  int i,n;
  item x;
  x = creaItem(55);
  printf("numero di interi da inserire: ");
  scanf("%d",&n );

  l=newList();

  for(i=0;i<n;i++)
  {
    l=consList(input_item(),l);
  }
  outputList(l);

  printf("%d\n",cercaElemento(x,l));

  x = cercaPosizione(4,l);
  if(x)
  {
      output_item(x);
      printf("\n");
  }

  l=switchACoppie(l);
  outputList(l);
  l=delMidEle(l);
  outputList(l);
}

int cercaElemento(item it,list l)
{
  int i;
  for(i=0;!emptyList(l);i++)
  {
      if(eq(getFirst(l),it))
      {
        return i;
      }
      l=tailList(l);
  }

  return -1;

}

item cercaPosizione(int pos,list l)
{
  int i;
  item it;

  it=NULLITEM;

  for(i=0;!emptyList(l) && i<pos;i++)
  {
    l=tailList(l);
  }

  if(!emptyList(l))
  {
    it = getFirst(l);
  }

  return it;
}

list switchACoppie(list l)
{
  int i,size;
  list app;

  size = sizeList(l);
  app = newList();
  if(size%2)
  {

    return l;
  }

  for(i=0;i<size;i+=2)
  {
    app=insertList(app,i,getItem(l,i+1));
    app=insertList(app,i+1,getItem(l,i));
  }

  return app;
}

list delMidEle(list l)
{

  return removeList(l,(sizeList(l)-1)/2);

}
