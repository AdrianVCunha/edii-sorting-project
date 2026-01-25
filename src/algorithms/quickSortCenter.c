#include "metrics/metric.h"
#include "utils/fileUtils.h"
#include "utils/arrayUtils.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

void quickSortCenter(int arr[], int left, int right, Metric* m) {

    int i, j;
    int pivot = arr[(left + right) / 2];

    partition(arr, left, right, &i, &j, pivot, m);

    if (j > left)
        quickSortCenter(arr, left, j, m);

    if (i < right)
        quickSortCenter(arr, i, right, m);
}

void runQuickSortCenter(int *array, int size, const char *datasetType, const char *outputPath, Metric *m) {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    quickSortCenter(array, 0, size-1, m);

    QueryPerformanceCounter(&end);
    m->executionTime = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

    printNumbersToFile(array, size, outputPath);
    printMetricToFile(size, "QhickSortCenter", datasetType, m);
    resetMetric(m);
    printf("\nFinished QuickSortCenter sort on %s (%d elements)", datasetType, size);
}