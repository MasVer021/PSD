#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "item.h"


struct puntoitem{
       float x;
       float y;
};

int eq(item a, item b){
   return a->x==b->x && a->y==b->y ;
}

float ascissa(item it){

  return it->x;

}

float ordinata(item it){

  return it->y;

}

item creaItem(float a, float o){
  item p = malloc(sizeof(*p));

  if(p)
  {
    p->x=a;
    p->y=o;
  }

  return p;
}

item input_item(){

  float x,y;
  printf("inserisci punto in modalità (x,y): ");
  scanf("%g,%g",&x,&y);

  return creaItem(x,y);
}

float distanza(item p1, item p2){
  return sqrt(pow((p1->x-p2->x),2)+pow((p1->y-p2->y),2));
}


void output_item(item it){
    printf("(%g,%g)",it->x,it->y);
}
