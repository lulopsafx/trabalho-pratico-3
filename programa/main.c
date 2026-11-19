#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "headers/pokemon.h"
#include "headers/pokelist.h"
#include "headers/pokecenter.h"

int main() {
    while (1) {
        int sortType;
        printf("Escolha o tipo de ordenação a ser usada:\n");
        printf("1. Simples        2. Sofisticada\n");
        scanf("%d", &sortType);

        switch (sortType) {
            case 1: {
                clock_t inicio = clock();
                functionCall1();
                clock_t fim = clock();
                double tempoGasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("Tempo de execução: %f segundos\n\n", tempoGasto);
                break;
            }
            case 2: {
                clock_t inicio = clock();
                functionCall2();
                clock_t fim = clock();
                double tempoGasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("Tempo de execução: %f segundos\n\n", tempoGasto);
                break;
            }
            default:
                printf("Entrada invalida\n");
                break;
        }
    }

    return 0;
}