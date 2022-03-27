#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "punto.h"
#include "utile.h"

#define M 20

int run_test_case(char *tc_id, int n);
int distanzamin(punto* punti ,float dis,int np);
punto* caricaArrPuntiF(float**cord, int n);



int main(int argc, char *argv[])
{
  FILE *test_suite, *result;
  char tc_id[M];
  int n = 0, m=0,i;
  float d = 0;
  punto *p;

  if(argc < 3)
  {
    printf("Nomi dei file mancanti \n");
    exit(1);
  }

  test_suite = fopen(argv[1], "r");
  result = fopen(argv[2], "w");

  if( test_suite == NULL || result == NULL ) {
      printf("Errore in apertura dei file \n");
      exit(1);
  }


  while(fscanf(test_suite, "%s%d", tc_id, &n) == 2)
  {

      fprintf(result,"%s ", tc_id);

       if(run_test_case(tc_id, n) == 1)
             fprintf(result, "PASS \n");
       else
             fprintf(result, "FAIL \n");
  }

  fclose(test_suite);  // chiusura file di input
  fclose(result);   // chiusura file di output


  return 0;
}


int run_test_case(char *tc_id,int n){
    char input_fname[M], output_fname[M], oracle_fname[M];
    float * in[2];
    float oracle;
    punto* punti;
    float d;
    int m;

    strcpy(input_fname,tc_id);
    strcat(input_fname,"_input.txt");

    strcpy(output_fname,tc_id);
    strcat(output_fname,"_output.txt");

    strcpy(oracle_fname,tc_id);
    strcat(oracle_fname,"_oracle.txt");

    in[0] = xcalloc(n+1,sizeof(float));
    in[1] = xcalloc(n+1,sizeof(float));

    finput_array(input_fname,in,n+1,&d);

    punti= caricaArrPuntiF(in,n);

    m=distanzamin(punti,d,n);

    foutput_array(output_fname,m);

    finput_array(oracle_fname,NULL,1,&oracle);

    printf("%s Le coppie di punti a distanza minore di %g sono %d\n",tc_id, d, m);

    return oracle==m ;
}

punto* caricaArrPuntiF(float**cord, int n)
{
  int i;
  punto *punti=xcalloc(n,sizeof(*punti));
  for(i=0;i<n;i++)
  {
    punti[i]=creapunto(cord[0][i],cord[1][i]);
  }
  return punti;
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
