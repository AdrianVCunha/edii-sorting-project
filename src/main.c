#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "metrics/metric.h"
#include "algorithms/bubble.h"
#include "algorithms/bubblestop.h"
#include "algorithms/insertionSort.h"
#include "algorithms/binarySort.h"
#include "algorithms/ternarySort.h"
#include "algorithms/shellSort.h"
#include "algorithms/selectionSort.h"
#include "algorithms/heapSort.h"
#include "algorithms/mergeSort.h"
#include "algorithms/radixSort.h"
#include "utils/fileUtils.h"
#include "utils/arrayGenerator.h"

#define SIZE 500000

int main(){
	srand(time(NULL));

	int *arr = malloc(SIZE * sizeof(int));

	char fileName[100];
	genImputRandom(SIZE, fileName);
	readArrayFromFile(arr, fileName, SIZE);

	Metric m = createMetric();

	//Random
	clock_t start = clock(); 
	shellSort(arr, SIZE, &m);
	clock_t end = clock();
	m.executionTime = ((double)(end - start)) / CLOCKS_PER_SEC;

	printNumbersToFile(arr, SIZE, "data/output/random/randomSorted.txt");
	printMetricToFile(SIZE, "shellSort", &m);

	free(arr);

	printf("\n\nFinished\n\n");

	return 0;
}
