#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "metrics/metric.h"
#include "algorithms/bubble.h"

int main(){
	
	int arr[10];

	for(int i = 0; i < 10; i++){
		arr[i] = rand() % 100;
	}

	printf("Array before sorting:\n");

	for(int i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n\n");

	Metric m = createMetric();

	clock_t start = clock(); 

	bubbleSort(arr, 10, &m);

	clock_t end = clock();
	m.executionTime = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("Array after sorting:\n");
	for(int i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n\nMetric after sorting:\n");
	printMetric(m);

	return 0;
}
