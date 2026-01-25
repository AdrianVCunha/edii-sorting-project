#include "metrics/metric.h"

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

void selectionSort(int arr[], int n, Metric *m);
void runSelectionSort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m);

#endif