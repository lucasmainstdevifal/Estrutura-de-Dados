#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"

int main(void) {
  Ponto *pt, *pt2;

  pt = criar(5,7);
  imprimir(pt);
  liberar(pt);

  pt2 = criar(7,7);
  modificarX(pt2, 6);
  liberar(pt2); 
  
  return 0;
}