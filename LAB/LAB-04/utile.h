// Interfaccia del modulo: file utile.h
#include <stdlib.h>
#include <stdio.h>
/* Specifica della funzione scambia */
void scambia(int * x, int * y);
char* ltrim(char * string);
char* rtrim(char * string);
char* trim(char * string);
// dichiarazione altre funzioni …
void *xcalloc(size_t numB, size_t size);
void *xmalloc( size_t size);
