#ifndef POKELIST_H
#define POKELIST_H
#include <stdio.h>
#include "pokemon.h"

typedef struct cell {
 Pokemon pikachu;
 struct cell* next;
} cell;

typedef struct pokelist {
 cell* first;
 cell* last;
} Pokelist;

int IsPokelistEmpty(Pokelist* list);
void startPokelist(Pokelist* list);
void PokelistInsert(Pokelist* list, Pokemon* pikachu);
int PokelistRemove(Pokelist* list, Pokemon* pikachu);
void printPokelist(Pokelist* list);
void readPokelist(Pokelist* list, int* totalPoke, int* totalEnergy);
void Pokelist2Array(Pokelist* list, Pokemon v[], int totalPoke);
void Array2Pokelist(Pokelist* list, Pokemon fakelist[], int totalPoke);
void PokelistLength(Pokelist* list, int len);

#endif