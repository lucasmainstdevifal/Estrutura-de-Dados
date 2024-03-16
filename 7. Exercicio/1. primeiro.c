// 1 - Implemente uma função que receba como parâmetros um vetor de números inteiros de tamanho n, 
// e retorne quantos números negativos estão armazenados nesse vetor e um novo vetor com os 
// valores negativos.

#include <stdio.h>
#include <stdlib.h>

// Função que conta os números negativos e cria um novo vetor com esses valores
int contarNegativos(int *vetor, int n, int **negativos) {
    int contador = 0;

    // Primeiro, contamos quantos números negativos existem no vetor
    for (int i = 0; i < n; i++) {
        if (vetor[i] < 0) {
            contador++;
        }
    }

    // Alocamos dinamicamente memória para o novo vetor de negativos
    *negativos = (int *) malloc(contador * sizeof(int));
    if (*negativos == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    // Preenchemos o novo vetor com os valores negativos
    int indice = 0;
    for (int i = 0; i < n; i++) {
        if (vetor[i] < 0) {
            (*negativos)[indice++] = vetor[i];
        }
    }

    // Retornamos a quantidade de números negativos encontrados
    return contador;
}

int main() {
    int vetor[] = {1, -2, 3, -4, 5, -6, 7, -8};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int *negativos;
    int qtdNegativos = contarNegativos(vetor, tamanho, &negativos);

    printf("Quantidade de numeros negativos: %d\n", qtdNegativos);
    printf("Numeros negativos no vetor: ");
    for (int i = 0; i < qtdNegativos; i++) {
        printf("%d ", negativos[i]);
    }
    printf("\n");

    // Liberamos a memória alocada dinamicamente
    free(negativos);

    return 0;
}