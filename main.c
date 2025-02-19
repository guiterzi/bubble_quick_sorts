#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bubble_sort.h"
#include "quicksort.h"
#include "pratos.h"  // Inclui a definição de 'struct Prato'

#define MAX_NAME_LENGTH 50
#define NUM_PRATOS 1000  // Definindo 1000 pratos

// Função para gerar um número aleatório entre `min` e `max`
int gerarAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Função para gerar um prato aleatório
struct Prato gerarPrato() {
    const char* carnes[] = {"frango", "bife", "peixe"};
    const char* frutas[] = {"maçã", "banana", "laranja"};
    const char* molhos[] = {"cremoso", "picante", "doce"};

    int prioridade = gerarAleatorio(1, 300000);  // Prioridade entre 1 e 300000
    int tempo = gerarAleatorio(1, 1000);         // Tempo entre 1 e 1000 minutos
    const char* carne = carnes[gerarAleatorio(0, 2)];
    const char* fruta = frutas[gerarAleatorio(0, 2)];
    const char* molho = molhos[gerarAleatorio(0, 2)];

    struct Prato prato;
    prato.prioridade = prioridade;
    prato.tempo = tempo;
    snprintf(prato.nome, MAX_NAME_LENGTH, "%s-%s-%s", carne, fruta, molho);

    return prato;
}

int main() {
    srand(time(NULL));  // Inicializa o gerador de números aleatórios

    // Vetor de pratos com 1000 elementos
    struct Prato pratos[NUM_PRATOS];

    // Preenche o vetor de pratos com valores aleatórios
    for (int i = 0; i < NUM_PRATOS; i++) {
        pratos[i] = gerarPrato();
    }

    // Exibe os pratos gerados antes da ordenação
    printf("Pratos gerados antes da ordenação:\n");
    for (int i = 0; i < NUM_PRATOS; i++) {
        printf("%d %d %s\n", pratos[i].prioridade, pratos[i].tempo, pratos[i].nome);
    }

    // Ordenação Bubble Sort
    bubbleSort(pratos, NUM_PRATOS);

    printf("\nPratos ordenados pelo Bubble Sort:\n");
    for (int i = 0; i < NUM_PRATOS; i++) {
        printf("%d %d %s\n", pratos[i].prioridade, pratos[i].tempo, pratos[i].nome);
    }

    // Ordenação Quick Sort
    quickSort(pratos, 0, NUM_PRATOS - 1);

    printf("\nPratos ordenados pelo Quick Sort:\n");
    for (int i = 0; i < NUM_PRATOS; i++) {
        printf("%d %d %s\n", pratos[i].prioridade, pratos[i].tempo, pratos[i].nome);
    }

    return 0;
}
