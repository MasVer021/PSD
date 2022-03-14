// FILE:   vettore.c
// restituisce 1 se i due vettori di ingresso sono uguali, 0 altrimenti

#include "utile.h"
#include "vettore.h"
#include <stdio.h>
#include <stdlib.h>

int confronta_array(int a[], int b[], int n)
{
	int i;

	for(i=0; a[i]==b[i] && i<n;i++);

	return i==n;
}

void foutput_array(char *file_name, int a[], int n)
{
	int i;
	FILE *fd;

  //aprire il file in scrittura
  fd=fopen(file_name,"w");

  //controllare che il file sia stato aperto correttamente
	if(!fd)
	{
		fprintf(stderr, "Errore nell'apertura del file: %s",file_name);
		exit(-1);
	}

  //e scrivere il contenuto (fprintf()) di a in fd
	for(i=0;i<n;i++)
	{
		fprintf(fd, "%d\n",a[i]);
	}

	// chiudere il file
	fclose(fd);
}

void finput_array(char *file_name, int a[], int n)
{
	int i;
	FILE *fd;

  //apertura file in lettura
	fd=fopen(file_name,"r");

	//Controllare se il file esiste e
	if(!fd)
	{
		fprintf(stderr, "Errore nell'apertura del file: %s",file_name);
		exit(-1);
	}

	//leggere il contenuto (fscanf()) da scrivere in array a
	for(i=0;i<n;i++)
	{
		fscanf(fd,"%d",&a[i]);
	}

	fclose(fd);
}

void ordina(int a[], int n)
{
	int i,j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
					scambia(&a[i], &a[j]);
			}
		}
	}

}
