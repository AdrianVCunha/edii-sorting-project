#include "metrics/metric.h"

#ifndef TERNARYSORT_H
#define TERNARYSORT_H

void ternarySort(int arr[], int n, Metric *m);
void runTernarySort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m);

#endif