#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "punto.h"
#include "utile.h"

int distanzamin(punto* punti ,float dis,int np);
punto caricapunti(char *p);


int main(int argc, char *argv[])
{

  int n = 0, m=0,i;
  float d = 0;
  punto *p;

  //carica tutto l'input: coppie e distanza
  if(argc<4)
  {
    printf("Parametri insufficienti<nomeprog [x1,y1] [x2,y2] ... [xn,yn] distanza>\n");
    exit(-1);
  }


  //calcola le distanze a coppie e controlla che siano minori di d
  n=argc-2;
  d=atof(argv[argc-1]);
  p=xcalloc(n,sizeof(*p));
  for(i=0;i<n;i++)
  {
    p[i]=caricapunti(argv[i+1]);
  }

  m=distanzamin(p,d,n);


  printf("Le coppie di punti a distanza minore di %g sono %d\n", d, m);


  return 0;
}


int distanzamin(punto* punti,float dis,int np)
{
  int i,j,count;
  count =0;

  for(i=0;i<np;i++)
  {
    for(j=i+1;j<np;j++)
    {
      if(distanza(punti[i],punti[j])<dis)
      {
        count++;
      }
    }
  }

  return count;
}

punto caricapunti(char *p)
{
  int i,j,lun;
  char * x = xcalloc(10,1);
  char * y = xcalloc(10,1);

  lun =strlen(p);
  for(j=1;isdigit(p[j])&&j<lun;j++);
  strncpy(x,p+1,j-1);
  strncpy(y,p+j+1,lun-2);

  return creapunto(atof(x),atof(y));

}
