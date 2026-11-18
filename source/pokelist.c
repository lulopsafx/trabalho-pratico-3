#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/pokemon.h"
#include "../headers/trainer.h"
#include "../headers/pokelist.h"


int IsPokelistEmpty(Pokelist* list){
    return (list->first == list->last);
}

void startPokelist(Pokelist* list){
    (*list).first = (cell*) malloc(sizeof(cell));
    (*list).last = (*list).first;
    list->first->next = NULL;
}
void PokelistInsert(Pokelist* list, Pokemon* pikachu){
    list->last->next = (cell*) malloc(sizeof(cell));
    (*list).last = (*list).last->next;
    list->last->pikachu = (*pikachu);
    list->last->next = NULL;
}
int PokelistRemove(Pokelist* list, Pokemon* pikachu){
    cell* aux;
    if(IsPokelistEmpty(list)){
        printf("Erro ao remover da lista\n");
        return 0;
    } else {
        (*pikachu) = list->first->next->pikachu;
        aux = (*list).first->next;
        (*list).first->next = aux->next;
        if(aux == list->last){
            list->last = list->first;
        }
        free(aux);
        return 1;
    }
}

void printPokelist(Pokelist* list){
    if(IsPokelistEmpty(list) == 1){
        printf("Pokelista vazia\n");
    } else {
        cell* aux;
        aux = list->first->next;
        while (aux != NULL){
            printf("%s\n", (*aux).pikachu.nome);
            aux = (*aux).next;
        }
    }  
}

void readPokelist(Pokelist* list, int* totalPoke){
    startPokelist(list);
    FILE *arq = fopen("../build/teste.txt", "r");
    if(arq == NULL){
        printf("Erro readPokelist");
    } else {
        char linha[256];
        while(fgets(linha, sizeof(linha), arq) != NULL){
            fscanf(arq, "%d", totalPoke);
            Pokemon pikachu;
            int pokedex;
            char nome[20];
            char tipo[20];
            int power;
            for(int i = 0; i<*totalPoke; i++){
                fscanf(arq, "%d %s %s %d %d", &pokedex, nome, tipo, &power);
                startPokemon(&pikachu, pokedex, nome, tipo, power);
                PokelistInsert(list, &pikachu);
            }
        }
    }
    fclose(arq);
}
    

void Pokelist2Array(Pokelist* list, Pokemon v[], int totalPoke){
    cell *aux = list->first->next;
    for (int i = 0; i < totalPoke; i++){
        v[i] = aux->pikachu;    
        aux = aux->next;
    }
}

void Array2Pokelist(Pokelist* list, Pokemon fakelist[], int totalPoke){
    for (int i = 0; i < totalPoke; i++){
        PokelistInsert(list, &fakelist[i]);
    }
}

//void PokelistLength(Pokelist* list, int len){
	//len = 0;
	//cell *aux = list->first->next;
	//while (aux != NULL) {
		//len++;
		//aux = aux->next;
	//}
//}