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

void printMetricToFile(int n, const char *algorithm, const char *type, Metric *m){

    char fileName[100];

    sprintf(fileName, "data/metrics/metricsAfterSort-%s.txt", algorithm);
    FILE *file = fopen(fileName, "a");
    if (file != NULL) {
        fprintf(file, "Algorithm: %s | Size: %d | type: %s\n", algorithm, n, type);
        fprintf(file, "Comparisons: %lld | Swaps: %lld | Execution time: %.16f\n", m->comparisons, m->swaps, m->executionTime);
        fprintf(file, "------------------------------------\n\n");

        fclose(file);
    }
}

void clearFile(const char *filename) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    fclose(f); 
}