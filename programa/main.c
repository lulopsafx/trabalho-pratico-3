#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/pokemon.h"
#include "headers/pokelist.h"
#include "headers/pokecenter.h"

// agora o prograa aceita arquivo via argumento (ex: .\tpAeds.exe teste_1000.txt)
int main(int argc, char* argv[]) {
    char arquivo[256] = "build/teste100.txt";
    if (argc > 1) {
        snprintf(arquivo, sizeof(arquivo), "%s", argv[1]);
    }

    while (1) {
        int sortType = -1;
        printf("Arquivo atual: %s\n", arquivo);
        printf("Escolha o tipo de ordenação a ser usada:\n");
        // Adicionada opcao 0 para sair
        printf("1. Simples        2. Sofisticada        0. Sair\n");
        int lido = scanf("%d", &sortType);
        if (lido == EOF) {
            break;
        }

        // removi calculo de tempo do main (ja e medido dentro de simpleSort e complexSort)
        switch (sortType) {
            case 1:
                functionCall1(arquivo);
                break;
            case 2:
                functionCall2(arquivo);
                break;
            case 0:
                return 0;
            default:
                printf("Entrada invalida\n");
                break;
        }
    }

    return 0;
}
