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


void finput_array(char *file_name, float*a[2], int n,float* dist)
{
  int i;
	FILE *fd;

	fd=fopen(file_name,"r");

	if(!fd)
	{
		fprintf(stderr, "Errore nell'apertura del file: %s",file_name);
		exit(-1);
	}


	for(i=0;i<n-1;i++)
	{
		fscanf(fd,"[%f,%f]\n",&a[0][i],&a[1][i]);
	}

  fscanf(fd,"%f",dist);

	fclose(fd);
}


void foutput_array(char *file_name,float m)
{
  FILE *fd;

  fd=fopen(file_name,"w");

  if(!fd)
	{
		fprintf(stderr, "Errore nell'apertura del file: %s",file_name);
		exit(-1);
	}

  fprintf(fd,"%f",m);

	fclose(fd);
}
