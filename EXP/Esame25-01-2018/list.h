#include "item.h"

typedef struct node *list;

list newList(void);
int emptyList(list l);
list consList(item val, list l);
list tailList(list l);
item getFirst (list l);
int sizeList (list l);
int posItem (list l, item val);
item getItem (list l, int pos);
list reverseList (list l);
void outputList (list l);
list removeList(list l,int pos);
list cloneList(list l);
list insertList(list l,int pos,item val);

list cancDaItem(list l,item el);
list fondiDaItem(list l1,list l2,item el);

/*
  specifica sintattica

    cancDaItem(list l,item el)-> list
    fondiDaItem(list l1,list l2,item el)-> list

  specifica semantica
    cancDaItem(list l,item el)-> l'
    pre:NULLA
    post: nella lista l passata in input devono
          rimanere solo di item che precedono l'ultima occorrenza
          dell'item el passato in ingresso, se el non è presente
          la lista viene lasciata intatta

    fondiDaItem(list l1,list l2,item el)-> l3
    pre:NULLA
    post:la lista l3 deve contenere tutti gli elementi comuni di
        l1 e l2 che pero seguono l'item passato in input el
        se el non è presente in entrambe le liste o se al seguito
        di el non vi sono elementi comuni l3 risulterà vuota

  progettazione
    cancDaItem(list l,item el)-> l':
    1-scorro tutta la lista salvando la posizione dell'nodo di valore el se lo trovo
    2- effettuo prima una cancellazione logica di tutti i nodi che seguono el
    3- libero l'area di memoria riservata ai nodi che seguono el

    fondiDaItem(list l1,list l2,item el)-> l3
    1- alloco la lista l3
    1- estraggo tutti gli elementi sia da l1 che da l2 fino a el incluso
    2- confronto ogni elemento rimasto in l1 con tutti gli elementi
      rimasti in l2 nel caso siano uguali li inserisco nella lista l3
    3- una volta terminati i confronti restituisco la lista l3 che conterrà
    tutti gli elementi comuni tra l1 e l2 successivi all'elmento el passato in
    input alla funzione


*/
