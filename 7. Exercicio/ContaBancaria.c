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