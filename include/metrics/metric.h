#ifndef METRIC_H
#define METRIC_H

typedef struct {
    long long comparisons;
    long long swaps;
    double executionTime;
} Metric;

Metric createMetric();

void resetMetric(Metric *m);

void printMetric(Metric m);

#endif