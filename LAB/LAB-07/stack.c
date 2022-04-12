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
  list pre = s->top;
  s->top = insertList(s->top,0,val);

  return pre!= s->top;
}


int pop(stack s)
{
  list pre = s->top;
  s->top = removeList(s->top,0);

  return pre!= s->top;
}

item top(stack s)
{

  return getFirst(s->top);
}
