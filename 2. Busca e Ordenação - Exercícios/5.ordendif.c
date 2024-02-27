#include <stdio.h>

// Função para trocar dois elementos de posição
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para encontrar o pivô e particionar o array
int particionar(int arr[], int inicio, int fim) {
    int pivo = arr[fim]; // Define o pivô como o último elemento
    int i = (inicio - 1); // Índice do menor elemento

    for (int j = inicio; j <= fim - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivo) {
            i++; // Incrementa o índice do menor elemento
            trocar(&arr[i], &arr[j]); // Troca arr[i] e arr[j]
        }
    }
    trocar(&arr[i + 1], &arr[fim]); // Coloca o pivô na posição correta
    return (i + 1); // Retorna a posição do pivô
}

// Função Quicksort
void quicksort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        // Encontra a posição do pivô
        int pivo = particionar(arr, inicio, fim);

        // Ordena os elementos antes e depois do pivô recursivamente
        quicksort(arr, inicio, pivo - 1);
        quicksort(arr, pivo + 1, fim);
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

    quicksort(numeros, 0, tamanho - 1);

    printf("Array ordenado em ordem crescente:\n");
    imprimirArray(numeros, tamanho);
    
    return 0;
}