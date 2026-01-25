#include "metrics/metric.h"

#ifndef SHELLSORT_H
#define SHELLSORT_H

void shellSort(int arr[], int n, Metric *m);
void runShellSort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m);

#endif