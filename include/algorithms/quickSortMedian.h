#include "metrics/metric.h"

#ifndef QUICKSORTMEDIAN_H
#define QUICKSORTMEDIAN_H

void partition(int arr[], int left, int right, int *i, int *j, int pivot, Metric* m);
int medianOfThree(int arr[], int a, int b, int c, Metric* m);
void quicksortMedian(int arr[], int left, int right, Metric* m);
void runQuickSortMedian(int *array, int size, const char *datasetType, const char *outputPath, Metric *m);

#endif