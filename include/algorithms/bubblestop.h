#include "metrics/metric.h"

#ifndef BUBBLESTOP_C
#define BUBBLESTOP_C

void bubbleStopSort(int arr[], int n, Metric *m);
void runBubbleStopSort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m);

#endif