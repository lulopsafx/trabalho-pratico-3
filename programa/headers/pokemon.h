#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>

typedef struct pokemon {
    int pokedex;
    char nome[20];
    char tipo[20];
    int power;
    // [CORRECAO] Removido campo energy (nao existe no TP3)
} Pokemon;

void setPokemon(Pokemon* pikachu, int pokedex, char nome[], char tipo[], int power);
void startPokemon(Pokemon* pikachu, int pokedex, char nome[], char tipo[], int power);
void printPokemon(Pokemon* pikachu);

#endif