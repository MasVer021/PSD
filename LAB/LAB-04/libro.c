#include <stdio.h>
#include <stdlib.h>
#include "libro.h"
#include "utile.h"

struct miolibro{
  char * titolo;
  char * editore;
  float prezzo;
  int anno;
};

libro creaLibro(char *t, char* e, float p, int a){
  libro l = xmalloc(sizeof(*l));

  l->titolo = t;
  l->editore = e;
  l->prezzo = p;
  l->anno = a;

  return l;

}

char* titolo(libro l)
{
    return l->titolo;
}

char* editore(libro l)
{
  return l->editore;
}

int anno(libro l)
{
  return l->anno;
}

float prezzo(libro l)
{
  return l->prezzo;
}

float sconto(libro* l, float percentuale)
{
    (*l)->prezzo=  (*l)->prezzo-((*l)->prezzo*(percentuale/100));

    return (*l)->prezzo;
}

void aggiorna (libro *l, int anno)
{
	(*l)->anno = anno;
}
