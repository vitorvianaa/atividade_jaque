#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teste.h"
/*
void verCarros() {
    printf("Carros disponiveis para alugar:\n");
    printf("===========\n");
    for (i = 0; i < totalPortifolio; i++) {
        printf("\nCodigo do carro [%d] - %s - Diaria: R$%d / dia\n", i, portifolio[i].nome, portifolio[i].diaria);
    }
    printf("\n===========\n");
    printf("Digite 1 para sair\n");
    int op;
    scanf("%d", &op);
}
*/

// Criando uma lista struct "portifolio" com os 8 modelos de carros
Carro portifolio[MAX_CARROS] = {
    {"Chevrolet Tracker", 120},
    {"Chevrolet Spin", 90},
    {"Hyundai HB20", 85},
    {"Hyundai Tucson", 120},
    {"Fiat Uno", 60},
    {"Fiat Mobi", 70},
    {"Volkswagen Gol", 80},
    {"Volkswagen Amarok", 150}
};

//Criando o struct do mesmo tipo para os carros que estão alugados
Carro alugados[MAX_CARROS];


void alugarCarro() {
    printf("Carros disponiveis para alugar:\n");
    printf("===========\n");
    for (i = 0; i < totalPortifolio; i++) {
        printf("\nCodigo do carro [%d] - %s - Diaria: R$%d / dia\n", i, portifolio[i].nome, portifolio[i].diaria);
    }
    printf("\n===========\n");
    printf("Digite o codigo do carro que deseja alugar:\n");
    int carroAlugado;
    scanf("%d", &carroAlugado);
	
	system("cls");
	
    printf("Voce escolheu o carro : %s. Deseja alugar por quantos dias?\n", portifolio[carroAlugado].nome);
    int diasAlugados;
    scanf("%d", &diasAlugados);

    printf("Revise seu pedido:\nCarro escolhido: %s\n", portifolio[carroAlugado].nome);
    printf("Total de diarias: %d\n", diasAlugados);
    printf("Valor Total do pedido: R$%d\n", diasAlugados * portifolio[carroAlugado].diaria);
	printf("Digite 1 para confirmar o pedido ou 0 para sair\n");
    int confirmarPedido;
    scanf("%d", &confirmarPedido);

    if (confirmarPedido == 1) {
        alugados[totalAlugados] = portifolio[carroAlugado];
        totalAlugados++;

        for (i = carroAlugado; i < totalPortifolio - 1; i++) {
            portifolio[i] = portifolio[i + 1];
        }
        totalPortifolio--;
        printf("-----Pedido Confirmado-----\n");
        printf("Pedido feito com sucesso!!\n");
        system("pause");

    } else {
        printf("Operação cancelada.\n");
    }
}

void devolverCarro() {
    printf("Lista de carros alugados:\n");
    for (i = 0; i < totalAlugados; i++) {
        printf("%d - %s\n", i, alugados[i].nome);
    }
    printf("Qual o codigo do carro você deseja devolver?\n");
    int devolvendo;
    scanf("%d", &devolvendo);

    portifolio[totalPortifolio] = alugados[devolvendo];
    totalPortifolio++;

    for (i = devolvendo; i < totalAlugados - 1; i++) {
        alugados[i] = alugados[i + 1];
    }
    totalAlugados--;

    printf("Devolução realizada com sucesso!\n");
}
