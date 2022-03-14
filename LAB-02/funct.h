#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char minimo(char *string);
char* minimo2(char **string,int dim);
void* xcalloc(size_t numB, size_t size);
char* leggiStringa(int maxLun);
char* merge(char** nomecognome);
char* incastona(char** nomecognome);
void inverti(char** nomecognome);
void crea (char** nomecognome);
void ordina(char *parola);
void ordinaInt(int *sequenza,int n);
void *xmalloc( size_t size);
char ** vocali_consonanti(char * parola);
void *xrealloc(void *p, size_t size);
