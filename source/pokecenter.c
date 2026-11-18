#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/pokemon.h"
#include "../headers/pokelist.h"
#include "../headers/pokecenter.h"


void simpleSort(Pokemon pokearray[]){

}

void complexSort(Pokemon pokearray[]){
    
}

void functionCall1(){
    
    Pokelist list;
    int totalPoke,
    readPokelist(&list, &totalPoke);

    Pokemon pokearray[totalPoke];
    Pokelist2Array(&list, pokearray, totalPoke);

    simpleSort(pokearray);

    for(int i = 0; i<totalPoke; i++){
        printf("%d %s %s %d", pokearray[i].pokedex, pokearray[i].nome, pokearray[i].tipo, pokearray[i].power);
    }
}

void functionCall2(){
    
    Pokelist list;
    int totalPoke,
    readPokelist(&list, &totalPoke);

    Pokemon pokearray[totalPoke];
    Pokelist2Array(&list, pokearray, totalPoke);

    complexSort(pokearray);

    for(int i = 0; i<totalPoke; i++){
        printf("%d %s %s %d", pokearray[i].pokedex, pokearray[i].nome, pokearray[i].tipo, pokearray[i].power);
    }
}
