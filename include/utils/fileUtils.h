#include "metrics/metric.h"

#ifndef FILEUTILS_H
#define FILEUTILS_H

void printNumbersToFile(int arr[], int n, const char *fileName);
void readArrayFromFile(int arr[], const char* filename, int n);
void printMetricToFile(int n, const char *algorithm, const char *type,  Metric *m);

#endif