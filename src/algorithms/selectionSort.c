#include "metrics/metric.h"

void selectionSort(int arr[], int n, Metric *m) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            (m->comparisons)++;

            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;

            (m->swaps)++;
        }
    }
}