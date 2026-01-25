#include "metrics/metric.h"

#ifndef QUICKSORTCENTER_H
#define QUICKSORTCENTER_H

void quickSortCenter(int arr[], int left, int right, Metric* m);
void runQuickSortCenter(int *array, int size, const char *datasetType, const char *outputPath, Metric *m);

#endif