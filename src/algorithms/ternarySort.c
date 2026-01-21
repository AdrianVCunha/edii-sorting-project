#include "metrics/metric.h"
#include "utils/swap.h"

void ternarySort(int arr[], int n, *metric m) {
    int auxiliar, esq, dir, m1, m2;

    for (int i = 1; i < n; i++) {
        auxiliar = arr[i];
        esq = 0;
        dir = i;

        // Busca ternária
        while (dir - esq > 1) {
            m1 = esq + (dir - esq) / 3;
            m2 = dir - (dir - esq) / 3;

            (m->comparisions)++;

            if (auxiliar < arr[m1]) {
                dir = m1;
            } else if (auxiliar > arr[m2]) {
                esq = m2 + 1;
            } else {
                esq = m1 + 1;
                dir = m2;
            }
        }

        // Ajuste final
        if (auxiliar > arr[esq]) esq++;

        // Deslocamentos
        for (int j = i; j > esq; j--) {
            arr[j] = arr[j - 1];
            (m->swaps)++;
        }

        arr[esq] = auxiliar;
        (m->swaps)++;
    }
}