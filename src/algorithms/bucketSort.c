#include "metrics/metric.h"
#include "utils/fileUtils.h"
#include "utils/arrayUtils.h"
#include "algorithms/shellSort.h"
#include "algorithms/bucketSort.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

void bucketSort(int arr[], int n, int bucketCount, Metric *m) {
    if (bucketCount > n) bucketCount = n;

    Bucket *buckets = malloc(bucketCount * sizeof(Bucket));

    int bucketSize = n / bucketCount + 1;
    for (int i = 0; i < bucketCount; i++) {
        buckets[i].data = malloc(bucketSize * sizeof(int));
        buckets[i].size = 0;
        buckets[i].capacity = bucketSize;
    }

    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        m->comparisons++;
        if (arr[i] < min) min = arr[i];

        m->comparisons++;
        if (arr[i] > max) max = arr[i];
    }

    int range = (max - min + 1) / bucketCount;
    if (range == 0) range = 1;

    for (int i = 0; i < n; i++) {
        int index = (arr[i] - min) / range;
        if (index >= bucketCount) index = bucketCount - 1;

        if (buckets[index].size >= buckets[index].capacity) {
            buckets[index].capacity *= 2;
            buckets[index].data = realloc( buckets[index].data, buckets[index].capacity * sizeof(int));
        }

        buckets[index].data[buckets[index].size++] = arr[i];
        (m->swaps)++;
    }

    for (int i = 0; i < bucketCount; i++) {
        if (buckets[i].size > 1) {
            shellSort(buckets[i].data, buckets[i].size, m);
        }
    }

    int k = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            arr[k++] = buckets[i].data[j];
            (m->swaps)++;
        }
        free(buckets[i].data);
    }

    free(buckets);
}




void runBucketSort(int *array, int size, const char *datasetType, const char *outputPath, Metric *m) {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    bucketSort(array, size, size, m);

    QueryPerformanceCounter(&end);
    m->executionTime = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

    printNumbersToFile(array, size, outputPath);
    printMetricToFile(size, "BucketSort", datasetType, m);
    resetMetric(m);
    printf("\nFinished BucketSort sort on %s (%d elements)", datasetType, size);
}