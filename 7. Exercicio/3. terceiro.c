// 3 -  Tendo como exemplo o TAD Ponto, crie o tipo de dados Círculo. 
// Defina sua estrutura e as operações necessárias para manipular o círculo.

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

//========================================================
#include <stdio.h>
#include <stdlib.h>
#include "Circulo.h"

Circulo* criarCirculo(int x, int y, double raio) {
    Circulo *c = (Circulo*)malloc(sizeof(Circulo));
    if (c == NULL) {
        printf("Erro ao alocar memória para o círculo\n");
        exit(1);
    }
    c->centro = criar(x, y);
    c->raio = raio;
    return c;
}

void imprimirCirculo(Circulo *c) {
    printf("\nCírculo:\nCentro: ");
    imprimir(c->centro);
    printf("\nRaio: %.2f\n", c->raio);
}

void moverCirculo(Circulo *c, int novoX, int novoY) {
    modificarX(c->centro, novoX);
    modificarY(c->centro, novoY);
}

void alterarRaio(Circulo *c, double novoRaio) {
    c->raio = novoRaio;
}

void liberarCirculo(Circulo *c) {
    liberar(c->centro);
    free(c);
}