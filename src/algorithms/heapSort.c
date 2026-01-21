#include "metrics/metric.h"
#include "utils/swap.h"

void criaHeap(int arr[], int inicio, int final, Metric* m) {
    int auxiliar = arr[inicio];   // guarda o pai
    int j = inicio * 2 + 1;     // filho da esquerda

    while (j <= final) {
        // Verifica se existe filho da direita
        if (j < final) {
            (m->comparisons)++; // comparação entre filhos
            if (arr[j] < arr[j + 1]) {
                j = j + 1; // aponta para o maior filho
            }
        }

        (m->comparisons)++; // comparação pai x maior filho
        if (auxiliar < arr[j]) {
            arr[inicio] = arr[j];  // filho sobe
            (m->swaps)++;

            inicio = j;
            j = 2 * inicio + 1;
        } else {
            j = final + 1; // encerra o while
        }
    }

    arr[inicio] = auxiliar; // pai desce para posicao correta
    (m->swaps)++;
}

void heapSort(int arr[], int N, Metric* m) {
    int i;
    int auxiliar;

    // 1ª fase: construir a heap máxima
    for (i = (N - 1) / 2; i >= 0; i--) {
        criaHeap(arr, i, N - 1, m);
    }

    // 2ª fase: ordenar
    for (i = N - 1; i >= 1; i--) {
        // troca o maior elemento (raiz) com o último
        auxiliar = arr[0];
        arr[0] = arr[i];
        arr[i] = auxiliar;
        (m->swaps)++;

        // reconstrói a heap
        criaHeap(arr, 0, i - 1, m);
    }
}
