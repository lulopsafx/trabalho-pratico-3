#ifndef POKECENTER_H
#define POKECENTER_H

#include <stdio.h>
#include "../headers/pokemon.h"
#include "../headers/pokelist.h"
typedef struct {
    Pokelist recuperados;
} Pokecenter;

typedef struct {
    long long comparacoes;
    long long movimentacoes;
} SortingMetric;

void startPokecenter(Pokecenter* pc);
int receiveRecoveredPokemon(Pokecenter* pc, Pokemon* pikachu);
void printRecoveredPokemons(Pokecenter* pc);
void reportRecoveredPokemons(Pokecenter* pc, const char* nome_arquivo);
void freePokecenter(Pokecenter* pc);
SortingMetric simpleSort(Pokecenter* pc);
SortingMetric complexSort(Pokecenter* pc);

// Imprime as metricas do metodo escolhido no terminal e grava em arquivo
void printSortingMetrics(const char* metodo, SortingMetric m, const char* nome_arquivo);
void functionCall1();
void functionCall2();

#endif