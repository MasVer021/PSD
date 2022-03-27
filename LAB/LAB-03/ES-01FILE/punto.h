

typedef struct miopunto *punto;

punto creapunto(float x, float y);
float ascissa(punto p);
float ordinata(punto p);
float distanza(punto p1, punto p2);
void stampa(punto p);
void foutput_array(char *file_name,float m);
void finput_array(char *file_name, float**a, int n,float* dist);
