#include "metrics/metric.h"
#include "utils/swap.h"

void particao(int arr[], int esquerda, int direita, int *i, int *j, int pivo, Metric* m) {

    *i = esquerda;
    *j = direita;

    while (*i <= *j) {

        while (arr[*i] < pivo && *i < direita) {
            (m->comparisons)++;
            (*i)++;
        }
        (m->comparisons)++;

        while (arr[*j] > pivo && *j > esquerda) {
            (m->comparisons)++;
            (*j)--;
        }
        (m->comparisons)++;

        if (*i <= *j) {
            int aux = arr[*i];
            arr[*i] = arr[*j];
            arr[*j] = aux;
            (m->swaps)++;

            (*i)++;
            (*j)--;
        }
    }
}

int medianaDeTres(int arr[], int a, int b, int c, Metric* m) {

    (m->comparisons)++;
    if (arr[a] < arr[b]) {
        (m->comparisons)++;
        if (arr[b] < arr[c]) return arr[b];
        (m->comparisons)++;
        if (arr[a] < arr[c]) return arr[c];
        return arr[a];
    } else {
        (m->comparisons)++;
        if (arr[a] < arr[c]) return arr[a];
        (m->comparisons)++;
        if (arr[b] < arr[c]) return arr[c];
        return arr[b];
    }
}

void quicksortMediana(int arr[], int esquerda, int direita, Metric* m) {

    int i, j;
    int meio = (esquerda + direita) / 2;

    int pivo = medianaDeTres(arr, esquerda, meio, direita, m);

    particao(arr, esquerda, direita, &i, &j, pivo, m);

    if (j > esquerda)
        quicksortMediana(arr, esquerda, j, m);

    if (i < direita)
        quicksortMediana(arr, i, direita, m);
}
