#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>

typedef struct pokemon {
    int pokedex;
    char nome[20];
    char tipo[20];
    int power;
    int energy;
} Pokemon;

void setPokemon(Pokemon* pikachu, int pokedex, char nome[], char tipo[], int power, int energy);
void startPokemon(Pokemon* pikachu, int pokedex, char nome[], char tipo[], int power, int energy);
void printPokemon(Pokemon* pikachu);

#endif