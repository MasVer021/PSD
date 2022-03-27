#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "punto.h"
#include "utile.h"

#define M 20

int run_test_case(char *tc_id, int n);
punto* caricaArrPuntiF(float**cord, int n);
void riordina(punto *punti, char coordinata, char criterio,int np);
int confrontoPunti(punto *punti1, punto *punti2, int np);




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
    punto* puntiOra;
    float m;
    float d;
    punto puntiMax[2];

    strcpy(input_fname,tc_id);
    strcat(input_fname,"_input.txt");

    strcpy(output_fname,tc_id);
    strcat(output_fname,"_output.txt");

    strcpy(oracle_fname,tc_id);
    strcat(oracle_fname,"_oracle.txt");

    in[0] = xcalloc(n+1,sizeof(float));
    in[1] = xcalloc(n+1,sizeof(float));

  
    finput_array(input_fname,in,n);

    punti= caricaArrPuntiF(in,n);


    riordina(punti, 'a', 'a',n);


    foutput_array(output_fname,punti,n);

    finput_array(oracle_fname,in,n);

    puntiOra= caricaArrPuntiF(in,n);




    return confrontoPunti(punti,puntiOra,n) ;
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

void riordina(punto *punti, char coordinata, char criterio,int np)
{
      if (criterio == 'a' && coordinata=='a')
          bubbleSortCrescentex(punti, np);
      if (criterio == 'a' && coordinata=='o')
          bubbleSortCrescentey(punti, np);
      if (criterio == 'd' && coordinata=='a')
          bubbleSortDecrescentex(punti, np);
      if (criterio == 'd' && coordinata=='o')
          bubbleSortDecrescentey(punti, np);

}

int confrontoPunti(punto *punti1, punto *punti2, int np)
{
  	int i;

  	for(i=0; i<np && ascissa(punti1[i])==ascissa(punti2[i]) && ordinata(punti1[i])==ordinata(punti2[i]) ;i++);
  	return i==np;

}
