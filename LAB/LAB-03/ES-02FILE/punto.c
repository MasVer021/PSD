#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"
#include "utile.h"

struct miopunto {
float x,y;
};

punto creapunto(float x, float y)
{

  punto p = xmalloc(sizeof(punto));
  p->x=x;
  p->y=y;
  return p;
}

float ascissa(punto p)
{

  return p->x;

}

float ordinata(punto p)
{
  return p->y;
}

float distanza(punto p1, punto p2)
{

  return sqrt(pow((p1->x-p2->x),2)+pow((p1->y-p2->y),2));

}

void  stampa (punto p)
{
  printf("(%g,%g)",p->x,p->y);
}


void finput_array(char *file_name, float*a[2], int n)
{
  int i;
	FILE *fd;

	fd=fopen(file_name,"r");

	if(!fd)
	{
		fprintf(stderr, "Errore nell'apertura del file: %s",file_name);
		exit(-1);
	}


	for(i=0;i<n;i++)
	{
		fscanf(fd,"[%f,%f]\n",&a[0][i],&a[1][i]);
	}

	fclose(fd);
}


void foutput_array(char *file_name,punto * pt,int n)
{
  FILE *fd;
  int i;
  fd=fopen(file_name,"w");

  if(!fd)
	{
		fprintf(stderr, "Errore nell'apertura del file: %s",file_name);
		exit(-1);
	}

  for(i=0;i<n;i++)
  {
      fprintf(fd,"[%g,%g]\n",ascissa(pt[i]),ordinata(pt[i]));

  }


	fclose(fd);
}

void swapPunto(punto *a, punto *b){
    punto temp = xmalloc(sizeof(*temp));
    temp = creapunto(ascissa(*a), ordinata(*a));
    *a = *b;
    *b = temp;
}

void bubbleSortCrescentex(punto* punti, int np){
    for (int i = 0; i < np - 1; i++){
        for(int j = i + 1; j < np; j++){
            if (ascissa(punti[i]) > ascissa(punti[j]))
                swapPunto(&punti[i], &punti[j]);
        }
    }
}

void bubbleSortCrescentey(punto* punti, int np){
    for (int i = 0; i < np - 1; i++){
        for(int j = i + 1; j < np; j++){
            if (ordinata(punti[i]) > ordinata(punti[j]))
                swapPunto(&punti[i], &punti[j]);
        }
    }
}

void bubbleSortDecrescentex(punto* punti, int np){
    for (int i = 0; i < np - 1; i++){
        for(int j = i + 1; j < np; j++){
            if (ascissa(punti[i]) < ascissa(punti[j]))
                swapPunto(&punti[i], &punti[j]);
        }
    }
}

void bubbleSortDecrescentey(punto* punti, int np){

    for (int i = 0; i < np - 1; i++){
        for(int j = i + 1; j < np; j++){
            if (ordinata(punti[i]) < ordinata(punti[j]))
                swapPunto(&punti[i], &punti[j]);
        }
    }
}
