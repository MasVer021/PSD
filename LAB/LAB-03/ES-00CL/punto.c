#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"
#include "utile.h"

struct miopunto {
float x,y;
};

punto creapunto(float x, float y){

  punto p = xmalloc(sizeof(punto));
  p->x=x;
  p->y=y;
  return p;
}

float ascissa(punto p){

  return p->x;

}

float ordinata(punto p){
  return p->y;
}

float distanza(punto p1, punto p2){

  return sqrt(pow((p1->x-p2->x),2)+pow((p1->y-p2->y),2));

}

void  stampa (punto p){
  printf("(%g,%g)",p->x,p->y);
}
