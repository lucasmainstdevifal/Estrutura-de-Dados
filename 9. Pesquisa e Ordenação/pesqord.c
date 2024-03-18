#include <stdio.h>

// Função de pesquisa sequencial
int pesquisaSequencial(int vetor[], int tamanho, int elemento) {
    int trocas = 0;
    for (int i = 0; i < tamanho; i++) {
        trocas++;
        if (vetor[i] == elemento) {
            return trocas;
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

// Função de busca binária
int buscaBinaria(int vetor[], int inicio, int fim, int elemento, int *trocas) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        (*trocas)++;
        if (vetor[meio] == elemento) {
            return (*trocas);
        } else if (vetor[meio] < elemento) {
            return buscaBinaria(vetor, meio + 1, fim, elemento, trocas);
        } else {
            return buscaBinaria(vetor, inicio, meio - 1, elemento, trocas);
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

// Função de ordenação em ordem crescente (Bubble Sort)
void ordenaVetor(int vetor[], int tamanho) {
    int trocas = 0;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                trocas++;
            }
        }
    }
    printf("Trocas realizadas durante a ordenacao: %d\n", trocas);
}

// Função principal
void main() {
    int vetor[] = {5, 3, 8, 1, 9, 2};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    // Chamada da função de pesquisa sequencial
    int elemento = 8;
    int trocasSequencial = pesquisaSequencial(vetor, tamanho, elemento);
    printf("Trocas realizadas na pesquisa sequencial: %d\n", trocasSequencial);

    // Ordena o vetor antes de realizar a busca binária
    ordenaVetor(vetor, tamanho);

    // Chamada da função de busca binária
    int trocasBinaria = 0;
    int resultado = buscaBinaria(vetor, 0, tamanho - 1, elemento, &trocasBinaria);
    printf("Trocas realizadas na busca binaria: %d\n", trocasBinaria);
    if (resultado != -1) {
        printf("Elemento encontrado na posicao: %d\n", resultado);
    } else {
        printf("Elemento nao encontrado.\n");
    }

    // Implementação de outro algoritmo de ordenação (Selection Sort)
    int vetor2[] = {5, 3, 8, 1, 9, 2};
    int tamanho2 = sizeof(vetor2) / sizeof(vetor2[0]);
    printf("\nComparacao entre os algoritmos de ordenacao:\n");
    printf("Bubble Sort:\n");
    ordenaVetor(vetor, tamanho);
    printf("Selection Sort:\n");
    selectionSort(vetor2, tamanho2);

    // Implementação recursiva dos algoritmos de busca e ordenação
    printf("\nImplementacao recursiva:\n");
    printf("Busca binaria recursiva:\n");
    // Implementação da busca binária recursiva
    int trocasRecursiva = 0;
    resultado = buscaBinariaRecursiva(vetor, 0, tamanho - 1, elemento, &trocasRecursiva);
    printf("Trocas realizadas na busca binaria recursiva: %d\n", trocasRecursiva);
    if (resultado != -1) {
        printf("Elemento encontrado na posicao: %d\n", resultado);
    } else {
        printf("Elemento nao encontrado.\n");
    }

    printf("Ordenacao recursiva:\n");
    // Implementação da ordenação recursiva
    ordenaVetorRecursivo(vetor, tamanho);
}

// Implementação do algoritmo Selection Sort
void selectionSort(int vetor[], int tamanho) {
    int trocas = 0;
    for (int i = 0; i < tamanho - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = vetor[i];
            vetor[i] = vetor[minIndex];
            vetor[minIndex] = temp;
            trocas++;
        }
    }
    printf("Trocas realizadas durante a ordenacao: %d\n", trocas);
}

// Implementação da busca binária recursiva
int buscaBinariaRecursiva(int vetor[], int inicio, int fim, int elemento, int *trocas) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        (*trocas)++;
        if (vetor[meio] == elemento) {
            return (*trocas);
        } else if (vetor[meio] < elemento) {
            return buscaBinariaRecursiva(vetor, meio + 1, fim, elemento, trocas);
        } else {
            return buscaBinariaRecursiva(vetor, inicio, meio - 1, elemento, trocas);
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

// Implementação da ordenação recursiva (Quick Sort)
void ordenaVetorRecursivo(int vetor[], int tamanho) {
    int trocas = 0;
    quickSort(vetor, 0, tamanho - 1, &trocas);
    printf("Trocas realizadas durante a ordenacao: %d\n", trocas);
}

void quickSort(int vetor[], int inicio, int fim, int *trocas) {
    if (inicio < fim) {
        int pIndex = partition(vetor, inicio, fim, trocas);
        quickSort(vetor, inicio, pIndex - 1, trocas);
        quickSort(vetor, pIndex + 1, fim, trocas);
    }
}

int partition(int vetor[], int inicio, int fim, int *trocas) {
    int pivot = vetor[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (vetor[j] < pivot) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            (*trocas)++;
        }
    }
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;
    (*trocas)++;
    return i + 1;
}