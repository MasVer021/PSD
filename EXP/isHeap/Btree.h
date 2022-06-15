#include "item.h"

#define NULLITEM NULL;

typedef struct node* Btree;
typedef struct node node;

Btree newBtree(void);
int emptyBtree(Btree T);
node * getRoot (Btree T);
item getItem(node *N);
Btree figlioSX(Btree T);
Btree figlioDX(Btree T);
Btree consBtree(item val, Btree sx, Btree dx);
void outputTree(Btree T);
void creafoglia(Btree T , node * foglia,int lato);
