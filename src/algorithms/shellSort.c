#include "metrics/metric.h"

void shellSort(int arr[], int n, Metric *m) {
    int h = 1;
    int aux, j;

    while (h < n) {
        h = 3 * h + 1;
    }

    while (h > 1) {
        h = h / 3;

        for (int i = h; i < n; i++) {
            aux = arr[i];
            j = i - h;

            while (j >= 0) {
                (m->comparisons)++;

                if (aux < arr[j]) {
                    arr[j + h] = arr[j];
                    (m->swaps)++;
                    j = j - h;
                } 
                else {
                    break;
                }
            }

            arr[j + h] = aux;
            (m->swaps)++;
        }
    }

}