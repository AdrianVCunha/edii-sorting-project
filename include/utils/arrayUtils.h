#include "metrics/metric.h"

#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H

int maxElement(int arr[], int n);
void freeAllArrays(
    int *randArray10k, int *ordArray10k, int *revArray10k,
    int *randArray100k, int *ordArray100k, int *revArray100k,
    int *randArray500k, int *ordArray500k, int *revArray500k
);
void partition(int arr[], int left, int right, int *i, int *j, int pivot, Metric* m);

#endif