#include "metrics/metric.h"
#include "utils/swap.h"

int maiorElemento(int arr[], int n) {
    int maior = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maior)
            maior = arr[i];
    }
    return maior;
}

void radixSort(int arr[], int n, Metric* m) {

    int maior = maiorElemento(arr, n);

    for (int exp = 1; maior / exp > 0; exp *= 10) {

        int saida[n];
        int contador[10] = {0};

        // Contagem dos dígitos
        for (int i = 0; i < n; i++) {
            int digito = (arr[i] / exp) % 10;
            contador[digito]++;
            (m->swaps)++;
        }

        // Posição acumulada
        for (int i = 1; i < 10; i++) {
            contador[i] += contador[i - 1];
        }

        // Monta o vetor de saída (estável)
        for (int i = n - 1; i >= 0; i--) {
            int digito = (arr[i] / exp) % 10;
            saida[contador[digito] - 1] = arr[i];
            contador[digito]--;
            (m->swaps)++;
        }

        // Copia de volta para o vetor original
        for (int i = 0; i < n; i++) {
            arr[i] = saida[i];
            (m->swaps)++;
        }
    }
}
