#include "metrics/metric.h"

#ifndef BINARYTIONSORT_H
#define BINARYTIONSORT_H

void binarySort(int arr[], int n, Metric *m);
void runBinarySort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m);

#endif