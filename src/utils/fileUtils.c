#include <stdio.h>
#include <stdlib.h>
#include "metrics/metric.h"

void printNumbersToFile(int arr[], int n, const char *fileName){

    FILE *file = fopen(fileName, "w");
    if(file != NULL){
        for(int i = 0; i < n; i++){
            fprintf(file, "%d\n", arr[i]);
        }
    }
    else{
        printf("Error creating file %s\n", fileName);
    }
    fclose(file);
}

void readArrayFromFile(int arr[], const char* fileName, int n) {
    FILE* f = fopen(fileName, "r");
    if(f != NULL){
        for (int i = 0; i < n; i++) {
        fscanf(f, "%d", &arr[i]);
        }
        fclose(f);
    }
}

void printMetricToFile(int n, const char *algorithm, Metric *m){

    FILE *file = fopen("data/metrics/metricsAfterSort.txt", "w");
    if (file != NULL) {
        fprintf(file, "Algorithm: %s | Size: %d\n", algorithm, n);
        fprintf(file, "Comparisons: %lld | Swaps: %lld\n", m->comparisons, m->swaps);
        fprintf(file, "------------------------------------\n\n");

        fclose(file);
    }
}