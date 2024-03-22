// 2 - Implemente a estrutura Carro com os campos: preço, fabricante e placa.  
// O programa deverá criar dinamicamente um vetor onde os dados dos n carros serão 
// guardados. Além de guardar, faça funções para: imprimir e atualizar um determinando 
// carro do vetor, dada sua placa. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float preco;
    char fabricante[50];
    char placa[10] ;
} Carro;

Carro * criarVetorQntCarros(int qtdCarros) {
    Carro *vetorCarros = (Carro *) malloc( qtdCarros * sizeof(Carro));
    if(vetorCarros == NULL) {
        printf("Erro ao alocar memória \n");
        exit(1);
    }
    
    return vetorCarros;
}

int main(){
    printf("Seja bem vindo ao registro de carros!\n");
    
    int qtdCarros;
    printf("Informe a quantidade de carros desejados para registrar: ");
    scanf("%d", &qtdCarros);

    Carro * carros = criarVetorQntCarros(qtdCarros);
    printf("Endereco de memoria alocado para um heap da quantidade informada para armazenar a quantidade de carros: %p" ,carros);

    for(int i=0; i<=qtdCarros; i++) {
        printf("\nCarro %d:\n", i + 1);
        printf("Digite o preco: ");
        scanf("%f", &carros[i].preco);
        printf("Digite o fabricante: ");
        scanf("%s", carros[i].fabricante);
        printf("Digite a placa: ");
        scanf("%s", carros[i].placa);
    }

    // Imprimindo informações sobre um carro dado sua placa
    char placaBusca[10];
    printf("\nDigite a placa do carro que deseja imprimir: ");
    scanf("%s", placaBusca);
    ImprimirCarro(carros, qtdCarros, placaBusca);

    // Atualizando o preço de um carro dado sua placa
    float novoPreco;
    printf("\nDigite a placa do carro que deseja atualizar o preco: ");
    scanf("%s", placaBusca);
    printf("Digite o novo preco: ");
    scanf("%f", &novoPreco);
    AtualizarCarro(carros, qtdCarros, placaBusca, novoPreco);

    // Liberando a memória alocada dinamicamente
    free(carros);

    return 0;
}