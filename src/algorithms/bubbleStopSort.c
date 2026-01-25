#include "metrics/metric.h"
#include "utils/fileUtils.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

void bubbleStopSort(int arr[], int n, Metric *m){

    int swapped;
    for(int i = 0; i < n-1; i++){

        swapped = 0;
        
        for(int j = 0; j < n-i-1; j++){
            
            (m->comparisons)++;
            if(arr[j] > arr[j + 1]){

                int aux = arr[j];
                arr[j] =  arr[j + 1];
                arr[j + 1] = aux;

                (m->swaps)++;
                swapped = 1;
            }
        }

        if(swapped == 0){
            break;
        }
    }
}

void runBubbleStopSort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m) {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    bubbleStopSort(array, size, m);

    QueryPerformanceCounter(&end);
    m->executionTime = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

    printNumbersToFile(array, size, outputPath);
    printMetricToFile(size, "BubbleStopSort", datasetType, m);
    resetMetric(m);
    printf("\nFinished BubbleStop sort on %s (%d elements)", datasetType, size);
}