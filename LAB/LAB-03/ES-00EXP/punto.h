

typedef struct miopunto *punto;

punto creapunto(float x, float y);
float ascissa(punto p);
float ordinata(punto p);
float distanza(punto p1, punto p2);
void stampa(punto p);
void foutput_array(char *file_name, void* outputStream,char * type,int numberOFElement);
