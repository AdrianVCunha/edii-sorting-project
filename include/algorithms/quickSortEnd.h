#include "metrics/metric.h"

#ifndef QUICKSORTEND_H
#define QUICKSORTEND_H

void quickSortEnd(int arr[], int left, int right, Metric* m);
void runQuickSortEnd(int *array, int size, const char *datasetType, const char *outputPath, Metric *m);

#endif