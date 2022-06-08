#include "item.h"
#include "list.h"
typedef struct c_PQ *PQueue;


PQueue newPQ(void);
int emptyPQ(PQueue q);
item getMax(PQueue q);
int deleteMax(PQueue q);
int insert (PQueue q, item ele);
list estraiPriorK(PQueue q,int k);
void aumentaPrior(PQueue q);
void PrintPQ(PQueue q);
