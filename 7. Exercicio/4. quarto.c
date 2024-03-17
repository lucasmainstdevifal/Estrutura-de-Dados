// 4 -  Implemente um TAD ContaBancaria, com os campos: número da conta e saldo.  
// As seguintes operações podem ser realizadas pelos clientes:

// •   Criar uma conta com um número e saldo inicial
// •   Depositar um valor
// •   Sacar um valor
// •   Imprimir o saldo

// ContaBancaria.h
#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

typedef struct {
    int numeroConta;
    double saldo;
} ContaBancaria;

ContaBancaria* criarConta(int numeroConta, double saldoInicial);

void depositar(ContaBancaria *conta, double valor);

void sacar(ContaBancaria *conta, double valor);

void imprimirSaldo(ContaBancaria *conta);

void liberarConta(ContaBancaria *conta);

#endif

// ContaBancaria.c
#include <stdio.h>
#include <stdlib.h>
#include "ContaBancaria.h"

ContaBancaria* criarConta(int numeroConta, double saldoInicial) {
    ContaBancaria *conta = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    if (conta == NULL) {
        printf("Erro ao alocar memória para a conta bancária\n");
        exit(1);
    }
    conta->numeroConta = numeroConta;
    conta->saldo = saldoInicial;
    return conta;
}

void depositar(ContaBancaria *conta, double valor) {
    conta->saldo += valor;
}

void sacar(ContaBancaria *conta, double valor) {
    if (valor > conta->saldo) {
        printf("Saldo insuficiente\n");
    } else {
        conta->saldo -= valor;
    }
}

void imprimirSaldo(ContaBancaria *conta) {
    printf("Número da conta: %d\n", conta->numeroConta);
    printf("Saldo: %.2f\n", conta->saldo);
}

void liberarConta(ContaBancaria *conta) {
    free(conta);
}

// ContaBancaria.h
#include <stdio.h>
#include "ContaBancaria.h"

int main() {
    ContaBancaria *conta1 = criarConta(12345, 1000.0);

    depositar(conta1, 500.0);
    sacar(conta1, 200.0);
    imprimirSaldo(conta1);

    liberarConta(conta1);

    return 0;
}