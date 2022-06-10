#include <stdio.h>
#include "list.h"



int main(void)
{

  list l = newList();
  list l2 = newList();

  l= consList(creaItem(1), l);
  l= consList(creaItem(2), l);
  l= consList(creaItem(3), l);
  l= consList(creaItem(4), l);
  l= consList(creaItem(5), l);
  l= consList(creaItem(6), l);
  l= consList(creaItem(7), l);
  l= consList(creaItem(8), l);
  l= consList(creaItem(9), l);
  l= consList(creaItem(10),l);
  l= consList(creaItem(11),l);
  l= consList(creaItem(12),l);



  l2= consList(creaItem(1), l2);
  l2= consList(creaItem(2), l2);
  l2= consList(creaItem(3), l2);
  l2= consList(creaItem(4), l2);
  l2= consList(creaItem(5), l2);
  l2= consList(creaItem(22), l2);
  l2= consList(creaItem(7), l2);
  l2= consList(creaItem(8), l2);
  l2= consList(creaItem(9), l2);
  l2= consList(creaItem(10),l2);
  l2= consList(creaItem(11),l2);
  l2= consList(creaItem(12),l2);

  /*outputList(l);
  l=cancDaItem(l,creaItem(9));
  outputList(l);
  outputList(l2);

  outputList(fondiDaItem(l,l2,creaItem(9)));*/
  return 0;
}
