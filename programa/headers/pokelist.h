#ifndef POKELIST_H
#define POKELIST_H

#include <stdio.h>
#include "../headers/pokemon.h"

#define MAX 50000

typedef struct pokelist {
    Pokemon* itens[MAX];
    int quantidade;
} Pokelist;

int IsPokelistEmpty(Pokelist* list);
void startPokelist(Pokelist* list);
int PokelistInsert(Pokelist* list, Pokemon* pikachu);
Pokemon* PokelistRemove(Pokelist* list, int pokedex);
Pokemon* searchPokelist(Pokelist* list, int pokedex);
int getPokelistLength(Pokelist* list);
long long sumPokelistPower(Pokelist* list);
void printPokelist(Pokelist* list);
void readPokelist(Pokelist* list, int* totalPoke);
void freePokelist(Pokelist* list);

#endif