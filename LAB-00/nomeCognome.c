#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char minimo(char *string);
char *minimo2(char **string,int dim);
void *xcalloc(size_t numB, size_t size);
void swapEle(char * a,char * b);
char * leggiStringa(int maxLun);
void leggi(char Stringa [],int taglia);
char* merge(char** nomecognome);
char* incastona(char** nomecognome);
void inverti(char** nomecognome);
void crea (char** nomecognome);
void ordina(char *parola);

#define MAXSTRING 50

int main(void) {
  char *NC[2];

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

char minimo (char* str){
    int len = strlen(str);
    char min = str[0];
    for (int i = 1; i < len; i++){
        if (min > str[i])
            min = str[i];
    }
    return min;
}

char* minimo2(char** tab, int dim){
    char* minimi = xcalloc(dim + 1,1);
    for (int i = 0; i < dim; i++){
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

void swapEle(char *a,char *b)
{
	char c=*a;
	*a=*b;
	*b=c;
}

char * leggiStringa(int maxLun)
{
	char S[maxLun],*S1;
	int lun;
	if(!S)
	{
		return NULL;
	}
	leggi(S,maxLun);
	lun = strlen(S);
	S1=malloc(lun+1*sizeof(char));
	if(!S1)
	{
		return NULL;
	}
	strcpy(S1,S);
	return S1;
}

void leggi(char Stringa [],int taglia)
{
   int lunghezza;

   fgets(Stringa,taglia+1,stdin);

   lunghezza = strlen(Stringa);

   if(lunghezza<taglia)
   {
     Stringa[lunghezza-1]='\0';
   }

}
char* merge(char** nomecognome)
{
  char *p = xcalloc(strlen(nomecognome[0])+strlen(nomecognome[1])+1,1);
  strcat(p,nomecognome[0]);
  strcat(p,nomecognome[1]);
  return p;

}
char* incastona(char** nomecognome)
{
  int indexlunga,indexcorta;
  char *p;

  if(strlen(nomecognome[0])>=strlen(nomecognome[1]))
  {
    indexlunga=0;
    indexcorta=1;
  }
  else
  {
    indexlunga=1;
    indexcorta=0;
  }

  p = xcalloc(strlen(nomecognome[indexlunga])+1,1);

  strncat(p,nomecognome[indexlunga],(strlen(nomecognome[indexlunga])-strlen(nomecognome[indexcorta]))/2);
  strcat(p,nomecognome[indexcorta]);
  strncat(p,nomecognome[indexlunga]+strlen(p),(strlen(nomecognome[indexlunga])-strlen(p)));

  return p;

}
void inverti(char** nomecognome)
{
  char *p=nomecognome[0];
  nomecognome[0]=nomecognome[1];
  nomecognome[1]=p;
}

void crea (char** nomecognome)
{
  char *p=xcalloc(7,1);
  strncat(p,nomecognome[0],3);
  strncat(p,nomecognome[1]+strlen(nomecognome[1])-3,3);
  nomecognome[2]=p;
}

void ordina(char *parola)
{
  int i, j,n;
  n = strlen(parola);
    for (i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if (parola[i] >parola[j])
                swapEle(&parola[i], &parola[j]);
        }
    }
}
