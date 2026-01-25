#include "metrics/metric.h"
#include "utils/fileUtils.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

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

void runMergeSort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m) {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    mergeSort(array, 0, size-1, m);

    QueryPerformanceCounter(&end);
    m->executionTime = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

    printNumbersToFile(array, size, outputPath);
    printMetricToFile(size, "MergeSort", datasetType, m);
    resetMetric(m);
    printf("\nFinished Merge sort on %s (%d elements)", datasetType, size);
}