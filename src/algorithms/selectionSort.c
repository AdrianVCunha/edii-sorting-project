#include "metrics/metric.h"
#include "utils/fileUtils.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

void selectionSort(int arr[], int n, Metric *m) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            (m->comparisons)++;

            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;

            (m->swaps)++;
        }
    }
}

void runSelectionSort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m) {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    selectionSort(array, size, m);

    QueryPerformanceCounter(&end);
    m->executionTime = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

    printNumbersToFile(array, size, outputPath);
    printMetricToFile(size, "SelectionSort", datasetType, m);
    resetMetric(m);
    printf("\nFinished Selection sort on %s (%d elements)", datasetType, size);
}
