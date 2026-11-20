#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/pokemon.h"

void setPokemon(Pokemon* pikachu, int pokedex, char nome[], char tipo[], int power) {
    if (pikachu != NULL) {
        pikachu->pokedex = pokedex;
        strncpy(pikachu->nome, nome, 19);
        pikachu->nome[19] = '\0';
        strncpy(pikachu->tipo, tipo, 19);
        pikachu->tipo[19] = '\0';
        pikachu->power = power;
    }
}

void startPokemon(Pokemon* pikachu, int pokedex, char nome[], char tipo[], int power) {
    setPokemon(pikachu, pokedex, nome, tipo, power);
}

void printPokemon(Pokemon* pikachu) {
    if (pikachu != NULL) {
        printf("Pokemon: %s | Pokedex: %d | Tipo: %s | Power: %d",
               pikachu->nome,
               pikachu->pokedex,
               pikachu->tipo,
               pikachu->power);
    }
}