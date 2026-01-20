#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "metrics/metric.h"
#include "algorithms/bubble.h"
#include "algorithms/bubblestop.h"

int main(){
	
	int arr[10000];

	for(int i = 0; i < 10000; i++){
		arr[i] = rand() % 100;
	}

	printf("Array before sorting:\n");

	for(int i = 0; i < 10000; i++){
		printf("%d ", arr[i]);
	}
	printf("\n\n");

	Metric m = createMetric();

	clock_t start = clock(); 

	bubbleSort(arr, 10000, &m);

	clock_t end = clock();
	m.executionTime = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("Array after sorting:\n");
	for(int i = 0; i < 10000; i++){
		printf("%d ", arr[i]);
	}
	
	printf("\n\nMetric after sorting:\n");
	printMetric(m);

	return 0;
}
