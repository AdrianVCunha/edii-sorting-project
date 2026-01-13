#include <stdio.h>
#include "metrics/metric.h"

Metric createMetric() {
    Metric m;
    m.comparisons = 0;
    m.swaps = 0;
    m.executionTime = 0.0;
    return m;
}

void resetMetric(Metric *m) {
    m->comparisons = 0;
    m->swaps = 0;
    m->executionTime = 0.0;
}

void printMetric(Metric m) {
    printf("Comparisons: %lld\n", m.comparisons);
    printf("Swaps: %lld\n", m.swaps);
    printf("Execution Time: %.6f seconds\n", m.executionTime);
}