
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "vettore.h"

# define M 20

int run_test_case(char *tc_id, int n){
    char input1_fname[M],input2_fname[M],output_fname[M], oracle_fname[M];
    int *in1,*in2,*or,*tot;

    //nome file input
    strcpy(input1_fname,tc_id);
    strcat(input1_fname,"_input1.txt");

    strcpy(input2_fname,tc_id);
    strcat(input2_fname,"_input2.txt");

    strcpy(output_fname,tc_id);
    strcat(output_fname,"_output.txt");

    strcpy(oracle_fname,tc_id);
    strcat(oracle_fname,"_oracle.txt");


    // allochiamo memoria per array di input
    in1 = xcalloc(n,sizeof(int));
    in2 = xcalloc(n,sizeof(int));
    // carica file di input
    finput_array(input1_fname,in1,n);
    finput_array(input2_fname,in2,n);
    // ordina array
    tot = sommaArr(in1,in2,n);
    // scrive file di output
    foutput_array(output_fname,tot,n);

    // allochiamo memoria per array oracolo
    or = xcalloc(n,sizeof(int));

    // carichiamo oracolo
    finput_array(oracle_fname,or,n);
    // confrontiamo array

    return confronta_array(tot,or,n);
}

int main(int argc, char *argv[])
{
    FILE *test_suite, *result;
    char tc_id[M];  // stringa contenente l'identificativo del test case
    int n, pass;

    if(argc < 3){
         printf("Nomi dei file mancanti \n");
         exit(1);
    }

    test_suite = fopen(argv[1], "r");  // apro file contenente test suite
    result = fopen(argv[2], "w");   // apro file contenente risultati test

    if( test_suite==NULL || result == NULL ) {
        printf("Errore in apertura dei file \n");
        exit(1);
    }

    /* Scansione del file di input nel ciclo while.
    Ad ogni iterazione si leggono i due elementi di una riga:
    l'identificativo del test case tc_id e il numero n di elementi
    da ordinare */

    while(fscanf(test_suite, "%s%d", tc_id, &n) == 2){
         pass = run_test_case(tc_id, n);

         fprintf(result,"%s ", tc_id);
         if(pass == 1)
               fprintf(result, "PASS \n");
         else
               fprintf(result, "FAIL \n");
         }

    fclose(test_suite);  // chiusura file di input
    fclose(result);         // chiusura file di output
}
