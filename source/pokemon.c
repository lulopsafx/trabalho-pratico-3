#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/pokemon.h"
#include "../headers/trainer.h"
#include "../headers/pokelist.h"


void setPokemon(Pokemon* pikachu, int pokedex, char nome[], char tipo[], int power, int energy){
    (*pikachu).pokedex = pokedex;
    strcpy((*pikachu).nome, nome);
    strcpy((*pikachu).tipo, tipo);
    (*pikachu).power = power;
    (*pikachu).energy = energy;
}
void startPokemon(Pokemon* pikachu, int pokedex, char nome[], char tipo[], int power, int energy){
    setPokemon(pikachu, pokedex, nome, tipo, power, energy);
}
void printPokemon(Pokemon* pikachu){
    printf("Pokémon: %s", (*pikachu).nome);
    printf("Pokedex: %d", (*pikachu).pokedex);
    printf("Tipo: %s", (*pikachu).tipo);
    printf("Power: %d", (*pikachu).power);
    printf("Energy: %d", (*pikachu).energy);
}
