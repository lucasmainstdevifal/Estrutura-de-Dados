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
        printf("Digite o preco do carro: ");
        
        printf("Digite o fabricante do carro: ");

        printf("Digite a placa do carro: ");
    }

    return 0;
}