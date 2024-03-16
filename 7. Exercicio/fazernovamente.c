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

Carro criarCarro(int qtdCarros){

}

int main(){
    printf("Seja bem vindo ao registro de carros!");
    
    int qtdCarros;
    printf("Informe a quantidade de carros desejados para registrar: ");
    scanf("%d", &qtdCarros);

    Carro carro = criarCarro(qtdCarros);

    return 0;
}