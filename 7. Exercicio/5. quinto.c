// 5 - Adapte a questão 2 de modo a utilizar o conceito de TADs.

// Ponto.h:
#ifndef PONTO_H
#define PONTO_H

typedef struct {
    int x;
    int y;
} Ponto;

Ponto* criarPonto(int x, int y);

void imprimirPonto(Ponto *p);

void modificarX(Ponto *p, int novoX);

void modificarY(Ponto *p, int novoY);

void liberarPonto(Ponto *p);

#endif

// Circulo.h:

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

// main.c:

#include <stdio.h>
#include "Circulo.h"

int main() {
    printf("Bem-vindo ao programa de manipulação de círculos!\n");

    Circulo *c1 = criarCirculo(0, 0, 5.0);
    imprimirCirculo(c1);

    moverCirculo(c1, 10, 10);
    printf("\nCírculo movido para (10, 10):\n");
    imprimirCirculo(c1);

    alterarRaio(c1, 8.0);
    printf("\nRaio do círculo alterado para 8.0:\n");
    imprimirCirculo(c1);

    liberarCirculo(c1);

    return 0;
}
