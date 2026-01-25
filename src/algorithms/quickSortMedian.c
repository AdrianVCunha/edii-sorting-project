#include "metrics/metric.h"
#include "utils/fileUtils.h"
#include "utils/arrayUtils.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>


int medianOfThree(int arr[], int a, int b, int c, Metric* m) {

    (m->comparisons)++;
    if (arr[a] < arr[b]) {
        (m->comparisons)++;
        if (arr[b] < arr[c]) return b;
        (m->comparisons)++;
        if (arr[a] < arr[c]) return c;
        return a;
    } else {
        (m->comparisons)++;
        if (arr[a] < arr[c]) return a;
        (m->comparisons)++;
        if (arr[b] < arr[c]) return c;
        return b;
    }
}

void quicksortMedian(int arr[], int left, int right, Metric* m) {

    int i, j;
    int middle = (left + right) / 2;

    int pivotIndex = medianOfThree(arr, left, middle, right, m);
    int pivot = arr[pivotIndex];

    partition(arr, left, right, &i, &j, pivot, m);

    if (left < j)
        quicksortMedian(arr, left, j, m);

    if (i < right)
        quicksortMedian(arr, i, right, m);
}

void runQuickSortMedian(int *array, int size, const char *datasetType, const char *outputPath, Metric *m) {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    quicksortMedian(array, 0, size-1, m);

    QueryPerformanceCounter(&end);
    m->executionTime = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

    printNumbersToFile(array, size, outputPath);
    printMetricToFile(size, "QuickSortMedian", datasetType, m);
    resetMetric(m);
    printf("\nFinished Quick sort median on %s (%d elements)", datasetType, size);
}