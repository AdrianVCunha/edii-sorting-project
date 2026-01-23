#include "metrics/metric.h"
#include "utils/arrayUtils.h"
#include <stdlib.h>

void radixSort(int arr[], int n, Metric *m){
    
    int max = maxElement(arr, n);
    int *output = malloc(n * sizeof(int));
    if (!output) return;

    for (int exp = 1; max / exp > 0; exp *= 10) {
        int count[10] = {0};

        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[--count[digit]] = arr[i];
            m->swaps++;
        }

        // Copy back to the original array
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
            m->swaps++;
        }
    }

    free(output);
}