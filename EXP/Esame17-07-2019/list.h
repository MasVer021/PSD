#include "item.h"

typedef struct c_list *list;

list newList(void);
int emptyList(list l);
int insertList(list l,int pos,item val);
int removeList(list l,int pos);
int sizeList (list l);
item getItem (list l, int pos);
list reverseList (list l);
void outputList (list l);
