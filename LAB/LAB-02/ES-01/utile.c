// Implementazione del Modulo: file utile.c
#include "utile.h"
/* commenti relativi alla progettazione
e realizzazione della funzione scambia */
void scambia(int * x, int * y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void *xcalloc(size_t numB, size_t size) {
  void *p;
  p = calloc(numB, size);
  if (!p) {
    fprintf(stderr, "Errore di allocazione di memoria di %lu bytes", size);
    exit(-1);
  }
  return p;
}

void *xmalloc( size_t size) {
  void *p;
  p = malloc(size);
  if (!p) {
    fprintf(stderr, "Errore di allocazione di memoria di %lu bytes", size);
    exit(-1);
  }
  return p;
}
