#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "pratos.h"

// Função de ordenação Bubble Sort
void bubbleSort(struct Prato pratos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Ordena por prioridade em ordem decrescente
            // Se as prioridades forem iguais, ordena pelo tempo em ordem crescente
            if (pratos[j].prioridade < pratos[j + 1].prioridade || 
                (pratos[j].prioridade == pratos[j + 1].prioridade && pratos[j].tempo > pratos[j + 1].tempo)) {
                
                // Troca os pratos
                struct Prato temp = pratos[j];
                pratos[j] = pratos[j + 1];
                pratos[j + 1] = temp;
            }
        }
    }
}

#endif // BUBBLESORT_H