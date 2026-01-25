#include <stdio.h>
#include "metrics/metric.h"
#include "utils/fileUtils.h"
#include <time.h>
#include <windows.h>

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

void runInsertionSort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m) {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    insertionSort(array, size, m);

    QueryPerformanceCounter(&end);
    m->executionTime = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

    printNumbersToFile(array, size, outputPath);
    printMetricToFile(size, "InsertionSort", datasetType, m);
    resetMetric(m);
    printf("\nFinished Insertion sort on %s (%d elements)", datasetType, size);
}
