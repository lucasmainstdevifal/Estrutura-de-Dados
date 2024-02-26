// Estrutura de Dados - Ordenação e Busca: 

//**************************************************************************************************************************************************************************
// 1.Busca Sequencial:
/* 
-> Conceito:
A busca sequencial é um método simples de encontrar um elemento em um conjunto de dados. Funciona percorrendo cada elemento do conjunto, um por um, até encontrar o 
elemento desejado ou percorrer todos os elementos.

Implementação em C:
Vamos começar com um exemplo simples. Suponha que temos um array de números inteiros e queremos encontrar a posição de um número específico nesse array.
*/

// Exemplo:
#include <stdio.h>

// Função para busca sequencial
int buscaSequencial(int arr[], int tamanho, int chave) {
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == chave)
            return i; // Retorna a posição se a chave for encontrada
    }
    return -1; // Retorna -1 se a chave não for encontrada
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

/*
    Neste exemplo, temos uma função buscaSequencial que recebe um array arr, seu tamanho tamanho e a chave que estamos procurando. A função percorre o array e verifica se cada 
elemento é igual à chave. Se encontrar a chave, retorna a posição; caso contrário, retorna -1.

* Exemplo:
Suponha que temos o seguinte array: {10, 7, 25, 14, 3} e queremos encontrar a posição do número 14.

-> A busca sequencial seguiria assim:

1. Começamos com o primeiro elemento: 10. Não é igual a 14, então seguimos em frente.
2. Próximo elemento: 7. Novamente, não é igual a 14.
3. Em seguida, 25. Também não é igual a 14.
4. Agora, chegamos a 14! Encontramos a chave e sua posição é 3.

Importante:
A busca sequencial é simples e fácil de entender, mas pode ser lenta para grandes conjuntos de dados.
Ela percorre o array de forma linear, elemento por elemento.
Sua complexidade de tempo é O(n), onde n é o número de elementos no array.

*/

//**************************************************************************************************************************************************************************
// 2.Busca Binária:
/*
Conceito:
A busca binária é um algoritmo eficiente para encontrar um elemento em um conjunto de dados ordenado. 
Funciona dividindo repetidamente ao meio o espaço de busca.

Funcionamento:

1. Inicialmente, o algoritmo compara o elemento que está no meio do array com a chave de busca.
2. Se o elemento do meio for igual à chave, a busca é concluída.
3. Se a chave for menor do que o elemento do meio, a busca continua na metade inferior do array
4. Se a chave for maior do que o elemento do meio, a busca continua na metade superior do array.
5. O  processo é repetido até que a chave seja encontrada ou não haja mais elementos para verificar.

Implementação em C:
Vamos ver um exemplo de implementação da busca binária em C:
*/

// Exemplo:
#include <stdio.h>

// Função para busca binária
int buscaBinaria(int arr[], int inicio, int fim, int chave) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

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
        printf("O elemento %d foi encontrado na posição %d.\n", chave, resultado);
    else
        printf("O elemento %d não foi encontrado no array.\n", chave);
    return 0;
}

//**************************************************************************************************************************************************************************
// 3. Ordenação:

// * BubbleSort

// * QuickSort


//**************************************************************************************************************************************************************************
// 4. Ordenação Avançada:

//**************************************************************************************************************************************************************************