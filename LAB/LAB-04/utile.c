// Implementazione del Modulo: file utile.c
#include "utile.h"
#include <string.h>
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

char * ltrim(char * string)
{
  int i;
  int n = strlen(string);

  for(i=0;string[i]==' ' && i<n;i++);

  strcpy(string,string+i);
  string[n-(i-1)]='\0';
  return string;
}

char* rtrim(char * string)
{
  int i;
  int n = strlen(string);

  for(i=n-1;(string[i]==' ' || string[i]=='\n' || string[i]=='\r') && i>0;i--);
  string[i+1]='\0';
  return string;
}

char* trim(char * string)
{

  ltrim(string);
  rtrim(string);

  return string;
}
