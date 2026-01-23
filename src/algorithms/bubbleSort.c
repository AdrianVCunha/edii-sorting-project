#include "metrics/metric.h"

void bubbleSort(int arr[], int n, Metric *m){

    for(int i = 0; i < n - 1; i++){
       
        for(int j = 0; j < n - i - 1; j++){
            
            (m->comparisons)++;
            if(arr[j] > arr[j + 1]){

                int aux = arr[j];
                arr[j] =  arr[j + 1];
                arr[j + 1] = aux;
                (m->swaps)++;
            }
        }
    }
}