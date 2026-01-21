#include "metrics/metric.h"
#include "utils/swap.h"

void binarySort(int arr[], int n, Metric* m) {
    int auxiliar, esq, dir, meio;

    for (int i = 1; i < n; i++) {
        auxiliar = arr[i];
        esq = 0;
        dir = i;

        // Busca binária
        while (esq < dir) {
            meio = (esq + dir) / 2;
            (m->comparisons)++;

            if (arr[meio] <= auxiliar)
                esq = meio + 1;
            else
                dir = meio;
        }

        // Deslocamentos
        for (int j = i; j > esq; j--) {
            arr[j] = arr[j - 1];
            (m->swaps)++;
        }

        arr[esq] = auxiliar;
        (m->swaps)++;
    }
}