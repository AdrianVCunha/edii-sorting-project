#include "metrics/metric.h"
#include "utils/swap.h"

void insertionSort(int arr[], int n, *metric m) {
    int auxiliar, j;

    for (int i = 1; i < n; i++) {
        auxiliar = V[i];
        j = i - 1;

        while (j >= 0) {
            (m->comparisions)++;

            if (auxiliar < V[j]) {
                V[j + 1] = V[j];
                (m->swaps)++;
                j--;
            } else {
                break;
            }
        }

        V[j + 1] = auxiliar;
        (m->swaps)++;
    }
}