// 2 - Implemente a estrutura Carro com os campos: preço, fabricante e placa.  
// O programa deverá criar dinamicamente um vetor onde os dados dos n carros serão guardados. 
// Além de guardar, faça funções para: imprimir e atualizar um determinando carro do vetor, 
// dada sua placa. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float preco;
    char fabricante[50]; // Ajustado para uma string para armazenar o nome do fabricante
    char placa[10]; // Ajustado para uma string para armazenar a placa
} Carro;

// Função para criar um vetor de carros
Carro* CriarCarro(int qntCarros) {
    Carro *carros = (Carro*) malloc(qntCarros * sizeof(Carro));
    if (carros == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    return carros;
}

// Função para imprimir um carro dado sua placa
void ImprimirCarro(Carro *carros, int qntCarros, const char* placa) {
    for (int i = 0; i < qntCarros; i++) {
        if (strcmp(carros[i].placa, placa) == 0) {
            printf("Carro encontrado:\n");
            printf("Preço: %.2f\n", carros[i].preco);
            printf("Fabricante: %s\n", carros[i].fabricante);
            printf("Placa: %s\n", carros[i].placa);
            return;
        }
    }
    printf("Carro com placa %s não encontrado.\n", placa);
}

// Função para atualizar um carro dado sua placa
void AtualizarCarro(Carro *carros, int qntCarros, const char* placa, float novoPreco) {
    for (int i = 0; i < qntCarros; i++) {
        if (strcmp(carros[i].placa, placa) == 0) {
            carros[i].preco = novoPreco;
            printf("Preço do carro com placa %s atualizado para %.2f.\n", placa, novoPreco);
            return;
        }
    }
    printf("Carro com placa %s não encontrado, não foi possível atualizar o preço.\n", placa);
}

int main() {
    printf("Bem-vindo ao sistema de gerenciamento de carros!\n");
    
    int qntCarros;
    printf("Digite a quantidade de carros que deseja guardar: ");
    scanf("%d", &qntCarros);

    Carro *carros = CriarCarro(qntCarros);

    // Preenchimento dos dados dos carros
    for (int i = 0; i < qntCarros; i++) {
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
    ImprimirCarro(carros, qntCarros, placaBusca);

    // Atualizando o preço de um carro dado sua placa
    float novoPreco;
    printf("\nDigite a placa do carro que deseja atualizar o preco: ");
    scanf("%s", placaBusca);
    printf("Digite o novo preco: ");
    scanf("%f", &novoPreco);
    AtualizarCarro(carros, qntCarros, placaBusca, novoPreco);

    // Liberando a memória alocada dinamicamente
    free(carros);

    return 0;
}