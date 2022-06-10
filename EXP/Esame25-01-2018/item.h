typedef struct puntoitem *item;
#define NULLITEM NULL


int eq(item a, item b);
item creaItem(int x);
item input_item();
int getInt(item it);
void output_item(item it);
void input_itemPun(item *x);
