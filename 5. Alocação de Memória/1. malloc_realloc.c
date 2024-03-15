#include <stdio.h>
#include <stdlib.h>

int main() {
    // Usando malloc para alocar espaço para um array de 5 inteiros
    int *ptr = (int *) malloc(5 * sizeof(int));
    if (ptr == NULL) {
        printf("Erro: Nao foi possivel alocar memoria.\n");
        return 1;
    }
    else {
        printf("Espaco alocado para 5 inteiros.\n");
    }

    // Preenchendo o array com valores
    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 10;
    }

    // Imprimindo os valores do array
    printf("Valores no array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Usando realloc para aumentar o tamanho do array para 10 inteiros
    ptr = (int *)realloc(ptr, 10 * sizeof(int));
    if (ptr == NULL) {
        printf("Erro: Nao foi possivel realocar memoria.\n");
        return 1;
    } 
    else {
        printf("Espaco realocado para 10 inteiros.\n");
    }

    // Preenchendo os novos elementos do array
    for (int i = 5; i < 10; i++) {
        ptr[i] = i * 10;
    }

    // Imprimindo os valores atualizados do array
    printf("Valores atualizados no array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Liberando a memória alocada
    free(ptr);

    return 0;
}
