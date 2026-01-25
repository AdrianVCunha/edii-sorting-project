#include "metrics/metric.h"

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

void insertionSort(int arr[], int n, Metric *m);
void runInsertionSort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m);

#endif