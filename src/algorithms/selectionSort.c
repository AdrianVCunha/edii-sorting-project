#include "metrics/metric.h"
#include "utils/swap.h"

void selectionSort(int arr[], int n, *metric m) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        // Procura o menor elemento
        for (j = i + 1; j < n; j++) {
            (m->comparisions)++;

            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        // Troca o menor com a posição atual
        if (min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;

            (m->swaps)++;
        }
    }
}
