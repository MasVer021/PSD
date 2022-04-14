#include <stdio.h>

#include "stack.h"
#include "list.h"
stack makeIntStack (void);
stack invertiStack(stack s);
stack merge (stack s1,stack s2);
void outputStack(stack s);
stack estrazione(stack s, int n);

int main(void)
{
  stack s = makeIntStack();
  stack inv = invertiStack(s);
  stack merged = merge(s,inv);
  stack extract=invertiStack(inv);

  printf("s\n");
  outputStack(s);

  printf("s'\n");
  outputStack(inv);

  printf("s''\n");
  outputStack(merged);


  extract = estrazione(extract,1);
  printf("estratto\n" );
  outputStack(extract);


}


stack makeIntStack (void)
{
  item it;
  stack s;

  s=newStack();
  it=input_item();

  while(getInt(it)!=-1)
  {
    push(it,s);
    it=input_item();
  }

  return s;
}

stack invertiStack(stack s)
{
  stack inv;
  list l;
  int val,i,size;


  inv = newStack();
  l=newList();

  while(!emptyStack(s))
  {
    val =getInt(top(s));
    insertList(l,0,creaItem(val));
    pop(s);
  }

  size = sizeList(l);

  for(i=0;i<size;i++)
  {
    val =getInt(getItem(l,i));
    push(creaItem(val),s);
  }

  l = reverseList(l);

  for(i=0;i<size;i++)
  {
    val =getInt(getItem(l,i));
    push(creaItem(val),inv);
  }

  while(!emptyList(l))
  {
    removeList(l,0);
  }


  return inv;
}

stack merge (stack s1,stack s2)
{
  stack merged;
  stack s1Inv,s2Inv;
  int val;

  merged = newStack();
  s1Inv = invertiStack(s1);
  s2Inv = invertiStack(s2);


  while(!emptyStack(s2Inv))
  {
    val = getInt(top(s2Inv));
    push(creaItem(val),merged);
    pop(s2Inv);
  }

  while(!emptyStack(s1Inv))
  {
    val = getInt(top(s1Inv));
    push(creaItem(val),merged);
    pop(s1Inv);
  }

  return merged;
}

stack estrazione(stack s, int n)
{
  stack app;
  int val;

  app = invertiStack(s);


  while(!emptyStack(s))
  {
    pop(s);
  }

  while(!emptyStack(app))
  {

    val = getInt(top(app));
    if(val!=n)
    {
      push(creaItem(val),s);
    }
    pop(app);
  }


  return s;
}

void outputStack(stack s)
{
  printf("(top->[");
  while(!emptyStack(s))
  {
    output_item(top(s));
    printf(",");
    pop(s);
  }
  printf("])\n");
}
