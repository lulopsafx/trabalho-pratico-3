#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/pokemon.h"
#include "../headers/pokelist.h"
#include "../headers/pokecenter.h"

// Criterio de ordenacao: menor power primeiro; desempate pelo menor numero da pokedex
static int comesBefore(Pokemon* a, Pokemon* b) {
    if (a->power != b->power) {
        return a->power < b->power;
    }
    return a->pokedex < b->pokedex;
}

//Partição do quickksort implementado fortemente baseado nos slides da thais
static void Particao(int Esq, int Dir, int *i, int *j, Pokemon **A, SortingMetric *m) {
    Pokemon *pivo, *aux;
    *i = Esq;
    *j = Dir;
    pivo = A[(*i + *j) / 2]; 

    do {
        while (1) {
            m->comparacoes++;
            if (comesBefore(A[*i], pivo)) {
                (*i)++;
            } else {
                break;
            }
        }

        while (1) {
            m->comparacoes++;
            if (comesBefore(pivo, A[*j])) {
                (*j)--;
            } else {
                break;
            }
        }

        if (*i <= *j) {
            if (*i != *j) {
                aux = A[*i];
                A[*i] = A[*j];
                A[*j] = aux;
                m->movimentacoes += 3;
            }
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

static void Ordena(int Esq, int Dir, Pokemon **A, SortingMetric *m) {
    int i, j;
    Particao(Esq, Dir, &i, &j, A, m);
    if (Esq < j) Ordena(Esq, j, A, m);
    if (i < Dir) Ordena(i, Dir, A, m);
}

static void QuickSort(Pokemon **A, int n, SortingMetric *m) {
    Ordena(0, n - 1, A, m);
}

void startPokecenter(Pokecenter* pc) {
    if (pc != NULL) {
        startPokelist(&pc->recuperados);
    }
}

int receiveRecoveredPokemon(Pokecenter* pc, Pokemon* pikachu) {
    if (pc == NULL || pikachu == NULL) {
        return 0;
    }
    return PokelistInsert(&pc->recuperados, pikachu);
}

void printRecoveredPokemons(Pokecenter* pc) {
    if (pc != NULL) {
        printPokelist(&pc->recuperados);
    }
}

void reportRecoveredPokemons(Pokecenter* pc, const char* nome_arquivo) {
    if (pc == NULL || nome_arquivo == NULL) {
        return;
    }

    FILE* arq = fopen(nome_arquivo, "w");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return;
    }

    fprintf(arq, "%d\n", pc->recuperados.quantidade);
    for (int i = 0; i < pc->recuperados.quantidade; i++) {
        Pokemon* p = pc->recuperados.itens[i];
        fprintf(arq, "Pokedex: %d | Nome: %s | Tipo: %s | Power: %d\n",
                p->pokedex,
                p->nome,
                p->tipo,
                p->power);
    }

    fclose(arq);
}

void freePokecenter(Pokecenter* pc) {
    if (pc != NULL) {
        freePokelist(&pc->recuperados);
    }
}

// Insertion Sort (Ordenacao Simples)
SortingMetric simpleSort(Pokecenter* pc) {
    SortingMetric m = {0, 0, 0.0};
    if (pc == NULL || pc->recuperados.quantidade <= 1) {
        return m;
    }

    clock_t inicio = clock();

    Pokemon** v = pc->recuperados.itens;
    int n = pc->recuperados.quantidade;

    for (int i = 1; i < n; i++) {
        Pokemon* chave = v[i];
        m.movimentacoes++;
        int j = i - 1;

        while (j >= 0) {
            m.comparacoes++;
            if (comesBefore(chave, v[j])) {
                v[j + 1] = v[j];
                m.movimentacoes++;
                j--;
            } else {
                break;
            }
        }

        v[j + 1] = chave;
        m.movimentacoes++;
    }

    clock_t fim = clock();
    m.tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    return m;
}

//quicksort
SortingMetric complexSort(Pokecenter* pc) {
    SortingMetric m = {0, 0, 0.0};
    if (pc == NULL || pc->recuperados.quantidade <= 1) {
        return m;
    }

    // Medicao de tempo feita diretamente dentro da funcao de sort
    clock_t inicio = clock();

    Pokemon** v = pc->recuperados.itens;
    int n = pc->recuperados.quantidade;

    QuickSort(v, n, &m);

    clock_t fim = clock();
    m.tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    return m;
}

void printSortingMetrics(const char* metodo, SortingMetric m, const char* nome_arquivo) {
    printf("\n--- Metricas de Ordenacao (%s) ---\n", metodo);
    printf("Comparacoes: %lld\n", m.comparacoes);
    printf("Movimentacoes: %lld\n", m.movimentacoes);
    // Imprime o tempo medido na ordenacao com 5 casas decimais
    printf("Tempo de execucao: %.5f segundos (%.5f ms)\n\n", m.tempo, m.tempo * 1000.0);;

    if (nome_arquivo != NULL) {
        FILE* arq = fopen(nome_arquivo, "a");
        if (arq == NULL) {
            printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
            return;
        }
        fprintf(arq, "--- Metricas de Ordenacao (%s) ---\n", metodo);
        fprintf(arq, "Comparacoes: %lld\n", m.comparacoes);
        fprintf(arq, "Movimentacoes: %lld\n", m.movimentacoes);
        //Grava o tempo medido na ordenacao em segundos com 5 casas decimais e em millisegundos com 3 casas decimais.
        fprintf(arq, "Tempo de execucao: %.5f segundos (%.5f ms)\n\n", m.tempo, m.tempo * 1000.0);
        fclose(arq);
    }
}

void functionCall1(const char* nome_arquivo) {
    Pokecenter pc;
    int totalPoke = 0;

    startPokecenter(&pc);
    readPokelist(&pc.recuperados, &totalPoke, nome_arquivo);

    SortingMetric m = simpleSort(&pc);

    //arquivo de saida com os Pokemon ordenados
    reportRecoveredPokemons(&pc, "saida_simples.txt");
    //saída em arquivo e no terminal das metricas de ordenação
    printSortingMetrics("Insertion Sort (Simples)", m, "metricas_ordenacao.txt");
    freePokecenter(&pc);
}

void functionCall2(const char* nome_arquivo) {
    Pokecenter pc;
    int totalPoke = 0;

    startPokecenter(&pc);
    readPokelist(&pc.recuperados, &totalPoke, nome_arquivo);

    SortingMetric m = complexSort(&pc);
    reportRecoveredPokemons(&pc, "saida_sofisticada.txt");

    printSortingMetrics("QuickSort (Sofisticada)", m, "metricas_ordenacao.txt");
    freePokecenter(&pc);
}
