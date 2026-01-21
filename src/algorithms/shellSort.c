#include "metrics/metric.h"
#include "utils/swap.h"

void shellSort(int arr[], int n, *metric m) {
    int h = 1;
    int auxiliar, j;

    // Geração da sequência de Knuth
    while (h < n) {
        h = 3 * h + 1;
    }

    // Ordenação
    while (h > 1) {
        h = h / 3;

        for (int i = h; i < n; i++) {
            auxiliar = arr[i];
            j = i - h;

            while (j >= 0) {
                (m->comparisions)++;

                if (auxiliar < arr[j]) {
                    arr[j + h] = arr[j];
                    (m->swaps)++;
                    j = j - h;
                } else {
                    break;
                }
            }

            arr[j + h] = auxiliar;
            (m->swaps)++;
        }
    }
}
