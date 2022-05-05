#include "item.h"

typedef struct c_queue *queue;
/*

specifica semantica

  newQueue() --> queue

  emptyQueue(queue q) --> intero

  dequeue(queue q)--> item

  enqueue(item val, queue q)--> intero

  outputStack(queue q)--> void

  reverseQueue(queue q)--> queue

  clonaQueue(queue q)--> queue

specifica sintattica

  newQueue() --> void
    pre:  NULLA
    post: NULLA

  emptyQueue(queue q) --> n
    pre:  NULLA
    post: n è il numero di nodi della queue q,
          se quest'ultima risulta non allocata n varrà -1

  dequeue(queue q)--> it
    pre:  NULLA
    post: it sarà il valore del nodo puntato dalla testa della queue q
          inoltre questo nodo verrà rimosso dalla coda
          se quest'ultima risulta non allocata o il numero degli elementi è uguale a 0
          it sara uguale alla consante NULLITEM

  enqueue(item val, queue q)--> stato
    pre:  NULLA
    post: stato assumerà il valore -1 nel caso in cui la queue non è allocata correttamente
          0 nel caso di problematiche legate all'allocazione del nuovo nodo
          e 1 nel caso in cui la procedura sia andata a buon fine
          inoltre la funzione avra come effetto collaterale l'inserimento di un nodo dal valore val in coda alla coda

  outputStack(queue q)--> void
    pre:  la queue q deve essere allocata correttamente
    post: l'effetto collaterale della funzione consiste nella stampa sullo standard output
          del valore dei vari nodi della queue q senza alterare quest'ultimi

  reverseQueue(queue q)--> q1
    pre:  NULLA
    post: nella queue q1 ci sara la versione invertità nell'ordine dei nodi della queue q senza alterare q

  clonaQueue(queue q)--> q1
    pre:  NULLA
    post: q1 è una copia distinta di q, (q non viene alterata)

// progettazione
  newQueue() --> void
    -allocazione di una nuova queue vuota


  emptyQueue(queue q) --> n
    -verifica se il numero degli elementi all'interno della queue è pari a 0


  dequeue(queue q)--> it
    -verifica che la queue sia allocata e che abbia elementi
    -salvataggio valore del nodo in testa
    -eliminiazione e deallocazione del nodo in testa
    -restituzione valore del nodo in testa precedentemente salvato


  enqueue(item val, queue q)--> stato
    -verifica che la queue sia allocata e che abbia elementi
    -allocazione nuovo nodo
    -valorizzazione nuovo nodo con valori passati come parametri alla funzione
    -inseimento in coda del nuovo nodo
    -resituire -1 in caso di errore di allocazione della coda
                0 in caso di errore di allocazione del nodo
                1 in caso di riuscita esecuzione della funzione


  outputStack(queue q)--> void
    -scorrere la queue stampando il valore dei nodi (dalla testa fino alla coda)

  reverseQueue(queue q)--> q1
    - verifica corretta allocazione della queue q
    - creazione coda vuota q1
    - creazione copia queue q (q2)
    - (3)inserimento nodo dal valore della costante definita NULLITEM all'interno della queue q2
    - (4)estrazione ed inserimento dei nodi della queue q2
      (5)fino al nodo precedente rispetto al nodo dal valore NULLITEM precedentemente inserimento (che chiameremo it)
    - (6)inseire il nodo con il valore di it nella queue q1
    - iterare i passi da 3 a 6 fino a quando la coda q2 non risulta vuota
    - restituire q1 che varrà NULL in caso di non corretta allocazione della coda passata come parametro,
      oppure sarà la versione con l'ordine dei nodi invertito di q

  clonaQueue(queue q)--> q1
  - verifica corretta allocazione della queue q
  - creazione coda vuota (q1)
  - (3)inserimento nodo dal valore della costante definita NULLITEM all'interno della queue q
  - (4)estrazione dei nodi della queue q
  - (5)reinserimento dei nodi nella queue q
  - (6)inserimento nodi nella queue q1
  - iterare i passi da 3 a 6 fino a quando il valore it non risulta uguale a NULLITEM
  - restituire q1 che sarà una versione perfettamente identica di q


*/

queue newQueue(void);

int emptyQueue(queue q);

item dequeue(queue q);

int enqueue(item val, queue q);

void outputStack(queue q);
queue reverseQueue(queue q);
queue clonaQueue(queue q);
