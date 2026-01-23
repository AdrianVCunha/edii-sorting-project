#include <stdio.h>
#include "metrics/metric.h"

void insertionSort(int arr[], int n, Metric *m) {
    int i, j, aux;

    for (i = 1; i <= n - 1; i++) {
        aux = arr[i];
        j = i-1;

        while(j>= 0){

            m->comparisons++;
            if(aux < arr[j]) {

                arr[j + 1] = arr[j];
                (m->swaps)++;
                j = j - 1;
            } 
            else {
                break;
            } 
        }

        if(j != i - 1) {
            arr[j + 1] = aux;
            (m->swaps++);
        }
    }
}
