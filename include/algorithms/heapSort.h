#include "metrics/metric.h"

#ifndef HEAPSORT_H
#define HEAPSORT_H

void heapify(int arr[], int i, int f, Metric *m);
void heapSort(int arr[], int n, Metric *m);

#endif