

typedef struct miopunto *punto;

punto creapunto(float x, float y);
float ascissa(punto p);
float ordinata(punto p);
float distanza(punto p1, punto p2);
void stampa(punto p);
void foutput_array(char *file_name,punto * pt,int n);
void finput_array(char *file_name, float**a, int n);
void bubbleSortCrescentex(punto* punti, int np);
void bubbleSortCrescentey(punto* punti, int np);
void bubbleSortDecrescentex(punto* punti, int np);
void bubbleSortDecrescentey(punto* punti, int np);
