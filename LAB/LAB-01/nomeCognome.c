#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funct.h"

    
#define MAXSTRING 50

int main(void) {
  char **NC;
  NC = xcalloc(2,sizeof(char *));
    
  printf("Fornire nome: ");
  char* nome = leggiStringa(MAXSTRING);

  printf("Fornire cognome: ");
  char* cognome = leggiStringa(MAXSTRING);
  NC[0]=nome;
  NC[1]=cognome;

 
  char *min = minimo2(NC,2);
  printf("Il minimo \ndi nome :%c \ndi cognome: %c\n", *min, *(min + 1));
  printf("\nIncastonamento: %s",incastona(NC));
  printf("\nMerge: %s",merge(NC));
  crea(NC);
  printf("\nNuova stringa: %s",NC[2]);
  
  ordina(NC[0]);
  ordina(NC[1]);
  printf("\nnome ordinato : %s\ncognome ordinato: %s", NC[0], NC[1]);
  return 0;
}

