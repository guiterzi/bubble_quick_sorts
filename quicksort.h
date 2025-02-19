#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "pratos.h"

// Função auxiliar para realizar a partição no Quick Sort
int partition(struct Prato pratos[], int low, int high) {
    struct Prato pivot = pratos[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        // Ordena por prioridade em ordem decrescente
        // Se as prioridades forem iguais, ordena pelo tempo em ordem crescente
        if (pratos[j].prioridade > pivot.prioridade || 
            (pratos[j].prioridade == pivot.prioridade && pratos[j].tempo < pivot.tempo)) {
            
            i++;
            struct Prato temp = pratos[i];
            pratos[i] = pratos[j];
            pratos[j] = temp;
        }
    }

    struct Prato temp = pratos[i + 1];
    pratos[i + 1] = pratos[high];
    pratos[high] = temp;

    return (i + 1);
}

// Função para realizar o Quick Sort
void quickSort(struct Prato pratos[], int low, int high) {
    if (low < high) {
        int pi = partition(pratos, low, high);

        quickSort(pratos, low, pi - 1);  // Recursão à esquerda
        quickSort(pratos, pi + 1, high); // Recursão à direita
    }
}

#endif // QUICKSORT_H
