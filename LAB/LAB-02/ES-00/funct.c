#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funct.h"

char minimo(char *str) {
  int len = strlen(str);
  char min = str[0];
  for (int i = 1; i < len; i++) {
    if (min > str[i])
      min = str[i];
  }
  return min;
}

char *minimo2(char **tab, int dim) {
  char *minimi = xcalloc(dim + 1, 1);
  for (int i = 0; i < dim; i++) {
    minimi[i] = minimo(tab[i]);
  }
  minimi[dim] = '\0';
  return minimi;
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

void *xrealloc(void *p, size_t size) {
  p = realloc(p, size);
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

static void swapEle(char *a, char *b) {
  char c = *a;
  *a = *b;
  *b = c;
}

static void swapEleInt(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

static void leggi(char Stringa[], int taglia) {
  int lunghezza;

  fgets(Stringa, taglia + 1, stdin);

  lunghezza = strlen(Stringa);

  if (lunghezza < taglia) {
    Stringa[lunghezza - 1] = '\0';
  }
}

char *leggiStringa(int maxLun) {
  char S[maxLun], *S1;
  int lun;
  if (!S) {
    return NULL;
  }

  leggi(S, maxLun);
  lun = strlen(S);
  S1 = xmalloc(lun + 1 * sizeof(char));
  if (!S1) {
    return NULL;
  }
  strcpy(S1, S);
  return S1;
}

char *merge(char **nomecognome) {
  char *p = xcalloc(strlen(nomecognome[0]) + strlen(nomecognome[1]) + 1, 1);
  strcat(p, nomecognome[0]);
  strcat(p, nomecognome[1]);
  return p;
}
char *incastona(char **nomecognome) {
  int indexlunga, indexcorta;
  char *p;

  if (strlen(nomecognome[0]) >= strlen(nomecognome[1])) {
    indexlunga = 0;
    indexcorta = 1;
  } else {
    indexlunga = 1;
    indexcorta = 0;
  }

  p = xcalloc(strlen(nomecognome[indexlunga]) + 1, 1);

  strncat(p, nomecognome[indexlunga],
          (strlen(nomecognome[indexlunga]) - strlen(nomecognome[indexcorta])) /
              2);
  strcat(p, nomecognome[indexcorta]);
  strncat(p, nomecognome[indexlunga] + strlen(p),
          (strlen(nomecognome[indexlunga]) - strlen(p)));

  return p;
}
void inverti(char **nomecognome) {
  char *p = nomecognome[0];
  nomecognome[0] = nomecognome[1];
  nomecognome[1] = p;
}

void crea(char **nomecognome) {
  nomecognome = realloc(nomecognome, sizeof(char *) * 3);
  char *p = xcalloc(7, 1);
  strncat(p, nomecognome[0], 3);
  strncat(p, nomecognome[1] + strlen(nomecognome[1]) - 3, 3);
  nomecognome[2] = p;
}

void ordina(char *parola) {
  int i, j, n;
  n = strlen(parola);
  for (i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (parola[i] > parola[j])
        swapEle(&parola[i], &parola[j]);
    }
  }
}

void ordinaInt(int *sequenza,int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (sequenza[i] > sequenza[j])
        swapEleInt(&sequenza[i], &sequenza[j]);
    }
  }
}

int isVocale(char carattere)
{
    carattere = tolower(carattere);
    if(carattere == 'a' || carattere == 'e'|| carattere == 'i'||carattere == 'o'||carattere == 'u' )
    {
      return 1;
    }
    return 0;
}

char ** vocali_consonanti(char * parola)
{
  int i,v,c;
  char **p;

  p=xcalloc(2,sizeof(char*));

  int n = strlen(parola);
  v=0;
  c=0;

  p[0] = xcalloc(n+1,sizeof(char));
  p[1] = xcalloc(n+1,sizeof(char));
  for(i=0;i<n;i++)
  {
    if(isalpha(parola[i]))
    {
        if(isVocale(parola[i]))
        {
          p[0][v]=parola[i];
          v++;
        }
        else
        {
          p[1][c]=parola[i];
          c++;
        }
    }
  }
    p[0] = xrealloc(p[0],strlen(p[0]+1));
    p[1] = xrealloc(p[1],strlen(p[1]+1));

    return p;


}
