#include "metrics/metric.h"
#include "utils/swap.h"

void intercalar(int arr[], int inicio, int meio, int fim, Metric* m) {

    int i = inicio;
    int j = meio + 1;
    int k = 0;

    int tamanho = fim - inicio + 1;
    int Tmp[tamanho];

    while (i <= meio || j <= fim) {

        if (i == meio + 1) {
            Tmp[k++] = arr[j++];
            (m->swaps)++;
        }
        else if (j == fim + 1) {
            Tmp[k++] = arr[i++];
            (m->swaps)++;
        }
        else {
            (m->comparisons)++;
            if (arr[j] < arr[i]) {
                Tmp[k++] = arr[j++];
                (m->swaps)++;
            } else {
                Tmp[k++] = arr[i++];
                (m->swaps)++;
            }
        }
    }

    // Copia do vetor auxiliar para o original
    for (i = inicio; i <= fim; i++) {
        arr[i] = Tmp[i - inicio];
        (m->swaps)++;
    }
}

void mergeSort(int arr[], int inicio, int fim, Metric* m) {

    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        mergeSort(arr, inicio, meio, m);
        mergeSort(arr, meio + 1, fim, m);
        intercalar(arr, inicio, meio, fim, m);
    }
}
