#include "metrics/metric.h"

#ifndef BUBBLE_H
#define BUBBLE_H

void bubbleSort(int arr[], int n, Metric *m);
void runBubbleSort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m);

#endif