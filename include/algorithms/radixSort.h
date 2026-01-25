#include "metrics/metric.h"

#ifndef RADIXSORT_H
#define RADIXSORT_H

void radixSort(int arr[], int n, Metric *m);
void runRadixSort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m);

#endif