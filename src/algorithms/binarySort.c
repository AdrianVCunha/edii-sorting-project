#include "metrics/metric.h"

void binarySort(int arr[], int n, Metric *m) {
    int aux, left, right, center;

    for (int i = 1; i < n; i++) {
        aux = arr[i];
        left = 0;
        right = i;

        while (left < right) {
            center = (left + right) / 2;

            (m->comparisons)++;
            if (arr[center] <= aux){
                left = center + 1;
            }
                
            else{
                right = center;
            }
                
        }

        for (int j = i; j > left; j--) {
            arr[j] = arr[j - 1];
            (m->swaps)++;
        }

        arr[left] = aux;
    }
}