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

void quicksortCentro(int arr[], int esquerda, int direita, Metric* m) {

    int i, j;
    int pivo = arr[(esquerda + direita) / 2];

    particao(arr, esquerda, direita, &i, &j, pivo, m);

    if (j > esquerda)
        quicksortCentro(arr, esquerda, j, m);

    if (i < direita)
        quicksortCentro(arr, i, direita, m);
}
