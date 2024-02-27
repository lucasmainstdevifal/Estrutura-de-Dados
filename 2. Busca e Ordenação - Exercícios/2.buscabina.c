// 2 – Implemente uma função que a busca binária num vetor de números inteiros;

#include <stdio.h>

// Função para busca binária
int buscaBinaria(int arr[], int inicio, int fim, int chave) {
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        // Se a chave estiver no meio
        if (arr[meio] == chave)
            return meio;

        // Se a chave for maior, ignora a metade inferior
        if (arr[meio] < chave)
            inicio = meio + 1;

        // Se a chave for menor, ignora a metade superior
        else
            fim = meio - 1;
    }

    // Se a chave não estiver presente no array
    return -1;
}

int main() {
    int numeros[] = {3, 7, 10, 14, 25};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int chave = 14;
    int resultado = buscaBinaria(numeros, 0, tamanho - 1, chave);
    if (resultado != -1)
        printf("O elemento %d foi encontrado na posicao %d.\n", chave, resultado);
    else
        printf("O elemento %d nao foi encontrado no array.\n", chave);
    return 0;
}