#include "metrics/metric.h"
#include "utils/fileUtils.h"
#include "utils/arrayUtils.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

void quickSortEnd(int arr[], int left, int right, Metric* m) {

    if (left >= right)
        return;

    int i, j;
    int pivot = arr[(left + right) / 2];

    partition(arr, left, right, &i, &j, pivot, m);

    if (left < j)
        quickSortEnd(arr, left, j, m);

    if (i < right)
        quickSortEnd(arr, i, right, m);
}

void runQuickSortEnd(int *array, int size, const char *datasetType, const char *outputPath, Metric *m) {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    quickSortEnd(array, 0, size-1, m);

    QueryPerformanceCounter(&end);
    m->executionTime = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

    printNumbersToFile(array, size, outputPath);
    printMetricToFile(size, "QhickSortEnd", datasetType, m);
    resetMetric(m);
    printf("\nFinished QuickSortEnd sort on %s (%d elements)", datasetType, size);
}