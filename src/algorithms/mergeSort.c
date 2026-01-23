#include "metrics/metric.h"
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right, Metric *m){
    int i = left;
    int j = mid + 1;
    int k = 0;
    int *temp = malloc((right - left + 1) * sizeof(int)); 

    while (i <= mid || j <= right) {

        if (i > mid) {
            temp[k++] = arr[j++];
            (m->swaps++);
        }
        else if (j > right) {
            temp[k++] = arr[i++];
            (m->swaps++);
        }
        else {
            (m->comparisons++);
            if (arr[j] < arr[i]) {
                temp[k++] = arr[j++];
            } 
            else {
                temp[k++] = arr[i++];
            }
            (m->swaps++);
        }

    }

    for(i = left; i <= right; i++){
        arr[i] = temp[i - left];
        (m->swaps)++;
    }

    free(temp);
}

void mergeSort(int arr[], int left, int right, Metric *m){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(arr, left, mid, m);
        mergeSort(arr, mid+1, right, m);
        merge(arr, left, mid, right, m);
    }
}