#include "metrics/metric.h"
#include "utils/swap.h"

void binarySort(int arr[], int n, *metric m) {
    int auxiliar, esq, dir, meio;

    for (int i = 1; i < n; i++) {
        auxiliar = V[i];
        esq = 0;
        dir = i;

        // Busca binária
        while (esq < dir) {
            meio = (esq + dir) / 2;
            (m->comparisions)++;

            if (V[meio] <= auxiliar)
                esq = meio + 1;
            else
                dir = meio;
        }

        // Deslocamentos
        for (int j = i; j > esq; j--) {
            V[j] = V[j - 1];
            (m->swaps)++;
        }

        V[esq] = auxiliar;
        (m->swaps)++;
    }
}