#include "metrics/metric.h"
#include "utils/fileUtils.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

void shellSort(int arr[], int n, Metric *m) {
    int h = 1;
    int aux, j;

    while (h < n) {
        h = 3 * h + 1;
    }

    while (h > 1) {
        h = h / 3;

        for (int i = h; i < n; i++) {
            aux = arr[i];
            j = i - h;

            while (j >= 0) {
                (m->comparisons)++;

                if (aux < arr[j]) {
                    arr[j + h] = arr[j];
                    (m->swaps)++;
                    j = j - h;
                } 
                else {
                    break;
                }
            }

            arr[j + h] = aux;
            (m->swaps)++;
        }
    }

}

void runShellSort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m) {

    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    shellSort(array, size, m);

    QueryPerformanceCounter(&end);
    m->executionTime = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

    printNumbersToFile(array, size, outputPath);
    printMetricToFile(size, "ShellSort", datasetType, m);
    resetMetric(m);
    printf("\nFinished Shell sort on %s (%d elements)", datasetType, size);
}