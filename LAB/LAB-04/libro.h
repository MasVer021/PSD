
typedef struct miolibro *libro;

libro creaLibro(char *titolo, char* editore, float prezzo, int anno);
char* titolo(libro l);
char* editore(libro l);
int anno(libro l);
float prezzo(libro l);
float sconto(libro* l, float percentuale);
void aggiorna(libro* l, int anno);
