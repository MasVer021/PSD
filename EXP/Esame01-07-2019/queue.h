#include "item.h"

typedef struct c_queue *queue;

queue newQueue(void);

int emptyQueue(queue q);

item dequeue(queue q);

int enqueue(item val, queue q);

void outputStack(queue q);

void cancFinoItem(item val, queue q);

queue fondiDaItem(item el, queue q1,queue q2);
/*
  specifica sintattica

    cancFinoItem(item val, queue q)-> void
    fondiDaItem(item el, queue q1,queue q2)-> queue

  specifica semantica
    cancFinoItem(item val, queue q)-> void
    pre:NULLA
    post: nella queue q passata in input devono
          rimanere solo di item che susseguono l'item
          val passato in ingresso, se val non è presente
          l'intera queue viene svuotata

    fondiDaItem(item el, queue q1,queue q2)-> q3
    pre:NULLA
    post:la queue q3 deve contenere tutti gli elementi comuni di
        q1 e q2 che pero seguono l'item passato in input el
        se el non è presente in entrambe le queue o se al seguito
        di el non vi sono elementi comuni q3 risulterà vuota

  progettazione
    cancFinoItem(item val, queue q)-> void:
    1-estraggo tutti gli elementi della queue
      fino a che non trovo val ed estraggo anche esso
      oppure fin quando la queue non risulta vuota

    fondiDaItem(item el, queue q1,queue q2)-> q3:
    1- alloco la queue q3
    1- estraggo tutti gli elementi sia da q1 cjhe da q2 fino a el incluso
    2- confronto ogni elemento rimasto in q1 con tutti gli elementi
      rimasti in q2 nel caso siano uguali li inserisco nella queue q3
    3- una volta terminati i confronti restituisco la coda q3 che conterrà
    tutti gli elementi comuni tra q1 e q2 successivi all'elmento el passato in
    input alla funzione


*/
