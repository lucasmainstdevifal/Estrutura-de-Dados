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