#include "metrics/metric.h"
#include "utils/fileUtils.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

void binarySort(int arr[], int n, Metric *m) {
    int aux, left, right, center;

    for (int i = 1; i < n; i++) {
        aux = arr[i];
        left = 0;
        right = i;

        while (left < right) {
            center = (left + right) / 2;

            (m->comparisons)++;
            if (arr[center] <= aux){
                left = center + 1;
            }
                
            else{
                right = center;
            }
                
        }

        for (int j = i; j > left; j--) {
            arr[j] = arr[j - 1];
            (m->swaps)++;
        }

        arr[left] = aux;
    }
}

void runBinarySort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m) {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    binarySort(array, size, m);

    QueryPerformanceCounter(&end);
    m->executionTime = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

    printNumbersToFile(array, size, outputPath);
    printMetricToFile(size, "BinarySort", datasetType, m);
    resetMetric(m);
    printf("\nFinished Binary sort on %s (%d elements)", datasetType, size);
}