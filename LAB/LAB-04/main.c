#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "libro.h"
#include "utile.h"


#define BUFFSIZE 100



libro libropiuvecchio(libro* biblioteca,int n);
libro libromenocostoso(libro* biblioteca,int n);
libro* ricercaeditore(libro* biblioteca,char* e,int n,int* nLibriEditore);
void scontalibri(libro* biblioteca, int a, float percentuale,int n);
libro* trovalibriprezzosimile(libro* biblioteca,int n);
float costototale(libro* biblioteca, int a,int n);
int eliminaLibri(libro* biblioteca, int a,int n);
int shiftSx(libro* biblioteca,int n,int pos);
libro * loadLibroFile(char *fileName, int n);
int contaLibriFile(char *fileName);
void stampaBiblioteca(libro * biblioteca,int n);

int main(int argc, char *argv[])
{

   int n;
   libro *biblioteca,*libT;
   libro l;
   int nLibTro;

   n=contaLibriFile(argv[1]);
   biblioteca=loadLibroFile(argv[1],n);

  /* printf("%g",prezzo(libromenocostoso(biblioteca,n)));
    l=libropiuvecchio(biblioteca,n);
    stampaBiblioteca(&l,1);
    l=libromenocostoso(biblioteca,n);
    stampaBiblioteca(&l,1);
    libT=ricercaeditore(biblioteca,"Bompiani", n,&nLibTro);
    stampaBiblioteca(libT,nLibTro);
    stampaBiblioteca(biblioteca,n);
    scontalibri(biblioteca, 2017, 12.8,n);
    stampaBiblioteca(biblioteca,n);
    stampaBiblioteca(trovalibriprezzosimile(biblioteca,n),2);
    printf("%g\n",costototale(biblioteca, 2017,n));
    stampaBiblioteca(biblioteca,n);
    n=eliminaLibri(biblioteca,2017,n);*/
    stampaBiblioteca(biblioteca,n);

  return 0;
}

libro libropiuvecchio(libro* biblioteca,int n)
{
  int annoV,i;

  libro vecchio;
  annoV = anno(biblioteca[0]);
  vecchio = biblioteca[0];
  for(i=1;i<n;i++)
  {
    if(anno(biblioteca[i])<annoV)
    {
      annoV = anno(biblioteca[i]);
      vecchio = biblioteca[i];
    }
  }

  return vecchio;
}

libro libromenocostoso(libro* biblioteca,int n)
{
  int i;
  float menoC;
  libro libroMenoc;
  menoC = prezzo(biblioteca[0]);
  libroMenoc = biblioteca[0];

  for(i=1;i<n;i++)
  {
    if(prezzo(biblioteca[i])<menoC)
    {
      menoC = prezzo(biblioteca[i]);
      libroMenoc = biblioteca[i];
    }
  }

  return libroMenoc;
}

libro* ricercaeditore(libro* biblioteca,char* e,int n,int* nLibTrov)
{
  int i,j,nLibriEditore;
  libro *lib;

  j=0;
  nLibriEditore=0;

  for(i=0;i<n;i++)
  {
    if(!strcmp(e,editore(biblioteca[i])))
    {
      nLibriEditore++;
    }
  }

  lib = (libro *)xcalloc(nLibriEditore,sizeof(libro));


  for(i=0;i<n;i++)
  {
    if(!strcmp(e,editore(biblioteca[i])))
    {
      lib[j]=biblioteca[i];
      j++;
    }
  }

  *nLibTrov=nLibriEditore;
  return lib;
}

void scontalibri(libro* biblioteca, int a, float percentuale,int n)
{
  int i;

  for(i=0;i<n;i++)
  {
    if(a==anno(biblioteca[i])){
      sconto(&biblioteca[i],percentuale);
    }
  }
}

libro* trovalibriprezzosimile(libro* biblioteca,int n)
{
  int i,j;
  float diffPre;
  libro* libriPreSim;

  libriPreSim=xcalloc(2,sizeof(libro));


  diffPre = fabs(prezzo(biblioteca[0])-prezzo(biblioteca[1]));
  libriPreSim[0] = biblioteca[0];
  libriPreSim[1] = biblioteca[1];

  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)
    {

      if(diffPre>fabs(prezzo(biblioteca[i])-prezzo(biblioteca[j])))
      {
        diffPre = fabs(prezzo(biblioteca[i])-prezzo(biblioteca[j]));
        libriPreSim[0] = biblioteca[i];
        libriPreSim[1] = biblioteca[j];

      }
    }
  }

  return libriPreSim;
}
float costototale(libro* biblioteca, int a,int n)
{
  int i;
  float costoTot;

  costoTot=0;

  for(i=0;i<n;i++)
  {
    if(a==anno(biblioteca[i]))
    {
      costoTot+=prezzo(biblioteca[i]);
    }
  }

  return costoTot;
}

int eliminaLibri(libro* biblioteca, int a,int n)
{
  int i,contElim;
  contElim=0;
  i=0;

  while(i<n)
  {

    if(a==anno(biblioteca[i]))
    {
      free(biblioteca[i]);
      n=shiftSx(biblioteca,n,i);
      contElim++;

    }
    else
    {
      i++;
    }

  }

  biblioteca=realloc(biblioteca,n-contElim*sizeof(libro));

  return n;
}


int shiftSx(libro* biblioteca,int n,int pos)
{
  int i;

  for(i=pos;i<n-1;i++)
  {
    biblioteca[i]=biblioteca[i+1];
  }
  return n-1;
}

int contaLibriFile(char *fileName)
{
  int count =0;
	FILE *fd;
  char a,p;


	fd=fopen(fileName,"r");

	if(!fd)
	{
		fprintf(stderr, "Errore nell'apertura del file: %s",fileName);
		exit(-1);
	}

  while(!feof(fd))
  {
    a=getc(fd);

    if(a=='\n')
    {
      count++;
    }

    if(a=='\r' && p =='\n')
    {
      count--;
    }
    p=a;
  }


	fclose(fd);
  return count/4;
}

libro * loadLibroFile(char *fileName, int n)
{
	FILE *fd;
  libro* libri;
  char * titolo;
  char * editore;
  int anno;
  float prezzo;
  int i;

  libri = xmalloc(sizeof(libro)*n);

	fd=fopen(fileName,"r");

	if(!fd)
	{
		fprintf(stderr, "Errore nell'apertura del file: %s",fileName);
		exit(-1);
	}

  titolo = xcalloc(BUFFSIZE,sizeof(char));
  editore = xcalloc(BUFFSIZE,sizeof(char));

  for(i=0;i<n;i++)
  {


    fgets(titolo,BUFFSIZE,fd);
    fgets(editore,BUFFSIZE,fd);
    fscanf(fd,"%d\n",&anno);
    fscanf(fd,"%g\n",&prezzo);
    libri[i]=creaLibro(trim(titolo), trim(editore), prezzo,anno);
  }


  free(titolo);
  free(editore);

  fclose(fd);

  return libri;
}

void stampaBiblioteca(libro * biblioteca,int n)
{
  int i;

  for(i=0;i<n;i++)
  {
    printf("----------------------------------------------------------------------------------------");
    printf("\nLIBRO #%d\n",i+1);
    printf("Titolo: %s\n",titolo(biblioteca[i]));
    printf("Editore: %s\n",editore(biblioteca[i]));
    printf("Anno: %d\n", anno(biblioteca[i]));
    printf("Prezzo: %g\n",prezzo(biblioteca[i]) );
  }
}
