#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "headers/pokemon.h"
#include "headers/pokelist.h"
#include "headers/pokecenter.h"

int main(){

    // Usa um switch case para fazer o menu interativo de escolher o algoritmo de ordenação

    while(1){
        int sortType;
        printf("Escolha o tipo de ordenação a ser usada:\n");
        printf("1. Simples        2. Sofisticada");
        scanf("%d", &sortType);
        
        switch(sortType){
            case 1:
                // Chama as funções para executar a ordenação simples, nesse caso insertion sort
                clock_t inicio = clock();
                functionCall1();
                clock_t fim = clock();
                double tempoGasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("Tempo de execução: %f segundos\n", tempoGasto);
            break;

            case 2: 
                // Chama as funções para executar a ordenação sofisticada, nesse caso quick sort
                clock_t inicio = clock();
                functionCall2();
                clock_t fim = clock();
                double tempoGasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("Tempo de execução: %f segundos\n", tempoGasto);
            break;

            default:
                // Caso o valor digitado não seja 1 ou 2, mostra uma mensagem de erro
                printf("Entrada invalida");
            break;
        }
    }
    
    return 0;

}