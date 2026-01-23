#include "metrics/metric.h"

#ifndef MERGESORT_H
#define MERGESORT_H

void merge(int arr[], int left, int mid, int right, Metric *m);
void mergeSort(int arr[], int left, int right, Metric *m);

#endif