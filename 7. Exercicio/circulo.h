#ifndef CIRCULO_H
#define CIRCULO_H

#include "Ponto.h"

typedef struct {
    Ponto *centro;
    double raio;
} Circulo;

Circulo* criarCirculo(int x, int y, double raio);

void imprimirCirculo(Circulo *c);

void moverCirculo(Circulo *c, int novoX, int novoY);

void alterarRaio(Circulo *c, double novoRaio);

void liberarCirculo(Circulo *c);

#endif