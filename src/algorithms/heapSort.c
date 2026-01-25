#include "metrics/metric.h"
#include "utils/fileUtils.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

void heapify(int arr[], int left, int right, Metric *m){
    int aux = arr[left];
    int j = 2 * left + 1;

    while(j <= right){

        (m->comparisons)++;
        if( j < right){

            (m->comparisons)++;
            if(arr[j] < arr[j+1]){
                j = j+1;
            }
        }
        (m->comparisons)++;
        if(aux < arr[j]){

            arr[left] = arr[j];
            (m->swaps)++;

            left = j;
            j = 2 * left + 1;
        }
        else{
            j = right + 1;
        }
    }
    arr[left] = aux;
}

void heapSort(int arr[], int n, Metric *m){
    for(int left = (n-1)/2; left >=0; left--){
        heapify(arr, left, n-1, m);
    }

    for(int left = n-1; left>=1; left--){
        int aux = arr[0];
        arr[0] = arr[left];
        arr[left] = aux;
        (m->swaps)++;

        heapify(arr, 0, left-1, m);
    }
}

void runHeapSort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m) {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    heapSort(array, size, m);

    QueryPerformanceCounter(&end);
    m->executionTime = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

    printNumbersToFile(array, size, outputPath);
    printMetricToFile(size, "HeapSort", datasetType, m);
    resetMetric(m);
    printf("\nFinished Heap sort on %s (%d elements)", datasetType, size);
}