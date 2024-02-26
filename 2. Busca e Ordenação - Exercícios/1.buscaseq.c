// 1 -  Implemente uma função que simule uma pesquisa sequencial num vetor de números inteiros;

#include <stdio.h>


int buscaSequencial(int arr[], int tamanho, int chave) {
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == chave)
            return i; 
    }
    return -1; 
}

int main() {
    
    int numeros[] = {10, 7, 25, 14, 3,47,48};
    int tamanho = sizeof(numeros);
    
    int chave;
    printf("Digite um número dentro das opções {10,7,25,14,3}: ");
    scanf("%d", &chave);
    
    // %d é inteiro , %f é float, %c char
    
    int resultado = buscaSequencial(numeros, tamanho, chave);
    if (resultado == -1)
        printf("O elemento %d não foi encontrado no array.\n", chave);
    else
        printf("O elemento %d foi encontrado na posição %d.\n", chave, resultado);
    return 0;
}