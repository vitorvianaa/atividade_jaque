#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teste2.c"
int i;
int main() {
    int opMenu = 0;

    while (1) {
        system("cls");
        if (opMenu == 0) {
            printf("===========\n");
            printf("Bem-Vindo a Locadora Viana!\n");
            printf("===========\n");
            printf("O que deseja fazer?\n");
            printf("[1] - Alugar um carro | [2] - Fazer uma devolucao\n");
            scanf("%d", &opMenu);
        }

        if (opMenu == 1) {
            system("cls");
            alugarCarro();
            opMenu = 0;
        } else if (opMenu == 2){
            system("cls");
            devolverCarro();
            printf("\nDigite 0 para voltar\n");
            scanf("%d", &opMenu);
        }
    }

    return 0;
}

