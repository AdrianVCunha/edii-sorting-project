#include "metrics/metric.h"
#include "utils/fileUtils.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

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

void runBubbleSort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m) {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    bubbleSort(array, size, m);

    QueryPerformanceCounter(&end);
    m->executionTime = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

    printNumbersToFile(array, size, outputPath);
    printMetricToFile(size, "BubbleSort", datasetType, m);
    resetMetric(m);
    printf("\nFinished Bubble sort on %s (%d elements)", datasetType, size);
}
