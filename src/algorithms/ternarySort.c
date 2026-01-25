#include "metrics/metric.h"
#include "utils/fileUtils.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

void ternarySort(int arr[], int n, Metric *m) {
    int aux, left, right, m1, m2;

    for (int i = 1; i < n; i++) {
        aux = arr[i];
        left = 0;
        right = i;

        while (right - left > 1) {
            m1 = left + (right - left) / 3;
            m2 = right - (right - left) / 3;

            (m->comparisons)++;

            if (aux < arr[m1]) {
                right = m1;
            } else if (aux > arr[m2]) {
                left = m2 + 1;
            } else {
                left = m1 + 1;
                right = m2;
            }
        }

        if (aux > arr[left]) left++;

        for (int j = i; j > left; j--) {
            arr[j] = arr[j - 1];
            (m->swaps)++;
        }

        arr[left] = aux;
        (m->swaps)++;
    }
}

void runTernarySort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m) {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    ternarySort(array, size, m);

    QueryPerformanceCounter(&end);
    m->executionTime = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

    printNumbersToFile(array, size, outputPath);
    printMetricToFile(size, "TernarySort", datasetType, m);
    resetMetric(m);
    printf("\nFinished Ternary sort on %s (%d elements)", datasetType, size);
}