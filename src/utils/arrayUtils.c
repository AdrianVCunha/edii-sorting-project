#include <stdio.h>
#include <stdlib.h>
#include "metrics/metric.h"

int maxElement(int arr[], int n){
    int max = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

void freeAllArrays( int *randArray10k, int *ordArray10k, int *revArray10k, int *randArray100k, int *ordArray100k, int *revArray100k, int *randArray500k, int *ordArray500k, int *revArray500k) {
    free(randArray10k);
    free(ordArray10k);
    free(revArray10k);

    free(randArray100k);
    free(ordArray100k);
    free(revArray100k);

    free(randArray500k);
    free(ordArray500k);
    free(revArray500k);
}

void partition(int arr[], int left, int right, int *i, int *j, int pivot, Metric* m) {

    *i = left;
    *j = right;

    while (*i <= *j) {

        while (arr[*i] < pivot) {
            (m->comparisons)++;
            (*i)++;
        }
        (m->comparisons)++;

        while (arr[*j] > pivot) {
            (m->comparisons)++;
            (*j)--;
        }
        (m->comparisons)++;

        if (*i <= *j) {
            int aux = arr[*i];
            arr[*i] = arr[*j];
            arr[*j] = aux;
            m->swaps++;

            (*i)++;
            (*j)--;
        }
    }
}