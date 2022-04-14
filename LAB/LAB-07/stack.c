#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "list.h"
#include "stack.h"

struct c_stack
{
  list top;
};

stack newStack(void)
{
  stack s;
  s=malloc(sizeof(*s));
  if(!s)
  {
    return NULL;
  }

  s->top = newList();
  return s;
}

int emptyStack(stack s)
{
  return emptyList(s->top);
}

int push(item val,stack s)
{
  return insertList(s->top,0,val);;
}


int pop(stack s)
{
  return removeList(s->top,0);
}

item top(stack s)
{

  return getItem(s->top,0);
}
