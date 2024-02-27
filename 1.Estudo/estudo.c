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
        int meio = ( inicio + fim )  / 2;

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
/*
-> Conceito: 
    A ordenação é o processo de reorganizar os elementos de uma coleção de dados de acordo 
    com um critério específico. Os algoritmos de ordenação são amplamente utilizados na 
    programação para organizar dados de maneira eficiente, facilitando a busca e a 
    manipulação subsequente desses dados.

    Algoritmos de Ordenação Simples:
        Vamos começar com alguns dos algoritmos de ordenação mais simples, que são 
        fáceis de entender e implementar.
*/

// * BubbleSort
// O Bubble Sort é um algoritmo de ordenação simples que percorre repetidamente a lista, 
// comparando elementos adjacentes e trocando-os se estiverem na ordem errada.

// Ele continua passando pela lista até que nenhum swap seja necessário, o que indica que a 
// lista está ordenada.

// Aqui está um exemplo de implementação do Bubble Sort em C:
void bubbleSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos arr[j] e arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// * QuickSort
/*
-> Conceito:
    O Quicksort é um algoritmo de ordenação eficiente e amplamente utilizado, conhecido por 
    sua velocidade e eficiência em muitos casos. Ele segue a abordagem de dividir para conquistar,
    dividindo o array em subarrays menores, ordenando esses subarrays e, em seguida, combinando-os.

-> Funcionamento:

    O Quicksort seleciona um elemento do array como pivô e rearranja os elementos do array de modo que
    todos os elementos menores que o pivô estejam à esquerda e todos os elementos maiores estejam à 
    direita. Em seguida, o Quicksort é aplicado recursivamente aos subarrays à esquerda e à direita 
    do pivô.

    * Exemplo:
*/

#include <stdio.h>

// Função para trocar dois elementos de posição
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para encontrar o pivô e particionar o array
int particionar(int arr[], int inicio, int fim) {
    int pivô = arr[fim]; // Define o pivô como o último elemento
    int i = (inicio - 1); // Índice do menor elemento

    for (int j = inicio; j <= fim - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivô) {
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
        int pivô = particionar(arr, inicio, fim);

        // Ordena os elementos antes e depois do pivô recursivamente
        quicksort(arr, inicio, pivô - 1);
        quicksort(arr, pivô + 1, fim);
    }
}

// Função para imprimir o array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    printf("Array original:\n");
    imprimirArray(arr, tamanho);
    quicksort(arr, 0, tamanho - 1);
    printf("Array ordenado:\n");
    imprimirArray(arr, tamanho);
    return 0;
}

/*
-> Explicação:

    * Vamos considerar o array de entrada {10, 7, 8, 9, 1, 5}.

    1) O pivô é escolhido como o último elemento, neste caso, 5.
    2) O array é particionado em torno do pivô de modo que os elementos menores que 5 estejam
    à esquerda e os maiores estejam à direita.
    3) Após a primeira iteração do Quicksort, o array se torna {1, 5, 8, 9, 10, 7}.
    4) O processo é repetido recursivamente nos subarrays à esquerda e à direita do pivô até 
    que todo o array esteja ordenado.
*/

/*
-> Escolha do Algoritmo:

    A escolha do algoritmo de ordenação depende do tamanho do conjunto de dados, da eficiência 
desejada e de outros fatores. Para conjuntos de dados pequenos ou quando a simplicidade é mais 
importante do que a eficiência, os algoritmos simples como Bubble Sort e Insertion Sort podem ser
adequados. Para conjuntos de dados maiores, algoritmos mais eficientes como Merge Sort, Quick Sort 
ou até mesmo algoritmos híbridos podem ser mais apropriados.

*/
//**************************************************************************************************************************************************************************
// 4. Ordenação Avançada:
// Algoritmo Merge Sort: conceito e implementação em C.
// Algoritmo Quick Sort: conceito e implementação em C.
// Comparação de desempenho entre os algoritmos de ordenação.
//**************************************************************************************************************************************************************************
// 5. Aplicações de Ordenação:
//
// Ordenação de strings.
// Ordenação de estruturas de dados complexas.
//**************************************************************************************************************************************************************************