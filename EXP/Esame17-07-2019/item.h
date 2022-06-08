typedef struct entry *item;

#define NULLITEM NULL

item newItem(int key,int value);
int isMaxKey(item a,item b);
int getKey(item a);
int getValue(item a);
void printItem( item a);
int setKey(item a,int key);
int setValue(item a, int value);
void printItemc( item a);
