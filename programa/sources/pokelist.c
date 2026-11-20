#include <stdio.h>
#include <stdlib.h>
#include "../headers/pokemon.h"
#include "../headers/pokelist.h"

int IsPokelistEmpty(Pokelist* list) {
    if (list == NULL) {
        return 1;
    }
    return (list->quantidade == 0);
}

void startPokelist(Pokelist* list) {
    if (list != NULL) {
        list->quantidade = 0;
    }
}

int PokelistInsert(Pokelist* list, Pokemon* pikachu) {
    if (list == NULL || pikachu == NULL || list->quantidade >= MAX) {
        return 0;
    }

    list->itens[list->quantidade] = pikachu;
    list->quantidade++;
    return 1;
}

Pokemon* PokelistRemove(Pokelist* list, int pokedex) {
    if (list == NULL) {
        return NULL;
    }

    for (int i = 0; i < list->quantidade; i++) {
        if (list->itens[i]->pokedex == pokedex) {
            Pokemon* removido = list->itens[i];

            for (int j = i; j < list->quantidade - 1; j++) {
                list->itens[j] = list->itens[j + 1];
            }

            list->quantidade--;
            return removido;
        }
    }

    return NULL;
}

Pokemon* searchPokelist(Pokelist* list, int pokedex) {
    if (list == NULL) {
        return NULL;
    }

    for (int i = 0; i < list->quantidade; i++) {
        if (list->itens[i]->pokedex == pokedex) {
            return list->itens[i];
        }
    }

    return NULL;
}

int getPokelistLength(Pokelist* list) {
    if (list == NULL) {
        return 0;
    }
    return list->quantidade;
}

long long sumPokelistPower(Pokelist* list) {
    if (list == NULL) {
        return 0;
    }

    long long soma = 0;
    for (int i = 0; i < list->quantidade; i++) {
        soma += list->itens[i]->power;
    }
    return soma;
}

void printPokelist(Pokelist* list) {
    if (IsPokelistEmpty(list)) {
        printf("Pokelista vazia\n");
        return;
    }

    for (int i = 0; i < list->quantidade; i++) {
        printPokemon(list->itens[i]);
        printf("\n");
    }
}

// read_pokelist recebe nome_arquivo e tenta abrir direto, em build/ ou em ../build/
void readPokelist(Pokelist* list, int* totalPoke, const char* nome_arquivo) {
    startPokelist(list);
    if (totalPoke != NULL) {
        *totalPoke = 0;
    }

    FILE *arq;
    if (nome_arquivo != NULL) {
        arq = fopen(nome_arquivo, "r");
    } else { arq = NULL;}

    if (arq == NULL && nome_arquivo != NULL) {
        char caminho[300];
        snprintf(caminho, sizeof(caminho), "build/%s", nome_arquivo);
        arq = fopen(caminho, "r");
        if (arq == NULL) {
            snprintf(caminho, sizeof(caminho), "../build/%s", nome_arquivo);
            arq = fopen(caminho, "r");
        }
    }
    if (arq == NULL) {
        printf("Erro readPokelist ao abrir %s\n", (nome_arquivo != NULL) ? nome_arquivo : "(null)");
        return;
    }

    /* mantive isso pois, iniciar o n=0 é uma boa prática no nosso caso pois como podemos rodar o arquivo mais de uma vez, podemos criar lixo de memória e o n fica com um valor diferente toda vez, mesmo com mesmo arquio.*/
    int n = 0;
    if (fscanf(arq, "%d", &n) == 1) {
        if (totalPoke != NULL) {
            *totalPoke = n;
        }

        // removi energy (nao existe na entrada dos testes)
        int pokedex, power;
        char nome[20];
        char tipo[20];

        for (int i = 0; i < n; i++) {
            // mudei a verificação do fscanf de 5 campos para 4 campos (pokedex, nome, tipo, power)
            if (fscanf(arq, "%d %19s %19s %d", &pokedex, nome, tipo, &power) == 4) {
                Pokemon* pikachu = (Pokemon*) malloc(sizeof(Pokemon));
                if (pikachu != NULL) {
                    startPokemon(pikachu, pokedex, nome, tipo, power);
                    // Libera o pokemon se a lista estiver cheia
                    if (!PokelistInsert(list, pikachu)) {
                        free(pikachu);
                    }
                }
            }
        }
    }

    fclose(arq);
}

void freePokelist(Pokelist* list) {
    if (list == NULL) {
        return;
    }

    for (int i = 0; i < list->quantidade; i++) {
        free(list->itens[i]);
    }

    list->quantidade = 0;
}