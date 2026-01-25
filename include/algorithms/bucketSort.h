#include "metrics/metric.h"

typedef struct {
    int *data;    
    int size;     
    int capacity;
} Bucket;

void bucketSort(int arr[], int n, int bucketCount, Metric *m);
void runBucketSort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m);