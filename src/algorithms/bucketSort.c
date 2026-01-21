#include "metrics/metric.h"
#include "utils/swap.h"

typedef struct {
    int *dados;   // vetor dinâmico
    int topo;     // quantidade de elementos
} Bucket;

void bubbleSort(int arr[], int n, Metric *m){

    for(int i = 0; i < n - 1; i++){
       
        for(int j = 0; j < n - i - 1; j++){
            m->comparisons++;
            
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                m->swaps++;
            }
        }
    }
}

void bucketSort(int arr[], int n, int numeroBaldes, Metric* m) {

    Bucket *baldes = malloc(numeroBaldes * sizeof(Bucket));

    // Inicializa os baldes
    for (int i = 0; i < numeroBaldes; i++) {
        baldes[i].dados = malloc(n * sizeof(int));
        baldes[i].topo = 0;
    }

    // Distribuição dos elementos nos baldes
    for (int i = 0; i < n; i++) {
        int j = numeroBaldes;

        while (j > 0) {
            (m->comparisons)++;
            if (arr[i] >= j * 10) {
                baldes[j - 1].dados[baldes[j - 1].topo++] = arr[i];
                (m->swaps)++;
                break;
            }
            j--;
        }
    }

    // Ordena individualmente cada balde
    for (int i = 0; i < numeroBaldes; i++) {
        if (baldes[i].topo > 0) {
            bubbleSort(baldes[i].dados, baldes[i].topo, m);
        }
    }

    // Retorna os elementos ao vetor original
    int k = 0;
    for (int i = 0; i < numeroBaldes; i++) {
        for (int j = 0; j < baldes[i].topo; j++) {
            arr[k++] = baldes[i].dados[j];
            (m->swaps)++;
        }
    }

    // Liberação da memória
    for (int i = 0; i < numeroBaldes; i++) {
        free(baldes[i].dados);
    }
    free(baldes);
}
