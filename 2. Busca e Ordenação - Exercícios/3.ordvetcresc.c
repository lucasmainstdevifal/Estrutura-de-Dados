// 3 – Implemente uma função que ordene um vetor em ordem crescente;

#include <stdio.h>

// Função para trocar dois elementos de posição
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para ordenar o vetor em ordem crescente
void ordCrescente(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos arr[j] e arr[j+1]
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Função para imprimir o vetor
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numeros[] = {10, 2, 3, 55, 1};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    
    printf("Array antes da ordenacao:\n");
    imprimirArray(numeros, tamanho);

    ordCrescente(numeros, tamanho);

    printf("Array ordenado em ordem crescente:\n");
    imprimirArray(numeros, tamanho);
    
    return 0;
}