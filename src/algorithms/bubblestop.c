#include "metrrics/metric.h"
#include "utils/swap.h"

void bubbleStopSort(int arr[], int n, Metric *m){

    int swapped;
    for(int i = 0; i < n-1; i++){

        swapped = 0;
        
        for(int j = 0; j < n-i-1; j++){
            m->comparisons++;
            
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                m->swaps++;
                swapped = 1;
            }
        }

        if(swapped == 0){
            break;
        }
    }
}