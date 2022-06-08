#include <stdio.h>
#include <stdlib.h>
#include "item.h"


struct entry{
      int key;
      int value;
};


int isMaxKey(item a,item b)
{
  if(!a || !b)
  {
    return -1;
  }
  return a->key > b->key;
}


int getKey(item a) // non si verifica la corretta allocazione di a
{
  return a->key;
}


int getValue(item a)// non si verifica la corretta allocazione di a
{
  return a->value;
}


int setKey(item a,int key)
{
  if(!a)
  {
    return 0;
  }

  a->key = key;
}

int setValue(item a,int value)
{
  if(!a)
  {
    return 0;
  }
  a->value = value;
}

item newItem(int key,int value)
{
  item it = malloc(sizeof(*it));
  if(it)
  {
    it->key = key;
    it->value = value;
  }


  return it;
}

void printItem( item a)
{
  printf("key:%d\tvalue:%d",a->key,a->value );
}


void printItemc( item a)
{
  printf("%c",a->key);
}
