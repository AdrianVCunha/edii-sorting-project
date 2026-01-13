#include "metrics/metric.h"
#include "utils/swap.h"

void bubbleSort(int arr[], int n, Metric *m){

    for(int i = 0; i < n - 1; i++){
       
        for(int j = 0; j < n - i - 1; j++){
            m->comparisons++;
            
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                m->swaps++;
            }
        }
    }
}