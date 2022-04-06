
typedef struct puntoitem *item;
#define NULLITEM NULL

int eq(item a, item b);
float ascissa(item it);
float ordinata(item it);
item creaItem(float a, float o);
item input_item();
float distanza(item p1, item p2);
void output_item(item it);
