#include <stdlib.h>
#include <stdio.h>
#include "Ponto.h"

struct ponto{
  int x;
  int y;
};

Ponto* criar(int x, int y){
  Ponto *p = (Ponto*)malloc(sizeof(Ponto));
  p->x = x;
  p->y = y;
  return p;
}

void imprimir(Ponto *p){
  printf("\n Ponto: %d, %d", p->x, p->y);
}

void modificarX(Ponto *p, int novox){
  p->x = novox;
  printf("Alteracao da coordenada x");
}

void liberar(Ponto *p){
  free(p);
  printf("\n Liberando o ponto");
}