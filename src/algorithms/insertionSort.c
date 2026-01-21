#include "metrics/metric.h"
#include "utils/swap.h"

void insertionSort(int arr[], int n, Metric* m) {
    int auxiliar, j;

    for (int i = 1; i < n; i++) {
        auxiliar = arr[i];
        j = i - 1;

        while (j >= 0) {
            (m->comparisons)++;

            if (auxiliar < arr[j]) {
                arr[j + 1] = arr[j];
                (m->swaps)++;
                j--;
            } else {
                break;
            }
        }

        arr[j + 1] = auxiliar;
        (m->swaps)++;
    }
}