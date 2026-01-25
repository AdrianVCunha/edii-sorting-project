#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "metrics/metric.h"
#include "algorithms/bubbleSort.h"
#include "algorithms/bubblestop.h"
#include "algorithms/insertionSort.h"
#include "algorithms/binarySort.h"
#include "algorithms/ternarySort.h"
#include "algorithms/shellSort.h"
#include "algorithms/selectionSort.h"
#include "algorithms/heapSort.h"
#include "algorithms/mergeSort.h"
#include "algorithms/radixSort.h"
#include "algorithms/quickSortCenter.h"
#include "algorithms/quickSortEnd.h"
#include "algorithms/quickSortMedian.h"
#include "algorithms/bucketSort.h"
#include "utils/fileUtils.h"
#include "utils/arrayGenerator.h"
#include "utils/arrayUtils.h"
#include "utils/menuUtils.h"

int main(){
	srand(time(NULL));

	printf("\nPlease wait... Generating input file...\n");
	genAllImputs();
	printf("All input files generated successfully.\n");
	printf("---x-----x----x-----x-----x-----x---\n");
	
	//generating all arrays for the test
	printf("Preparing arrays for algorithm benchmarking...\n");

	//10k
	int *randArray10k = malloc(10000 * sizeof(int));
	int *ordArray10k = malloc(10000 * sizeof(int));
	int *revArray10k = malloc(10000 * sizeof(int));

	if(randArray10k != NULL && ordArray10k != NULL && revArray10k != NULL){
		readArrayFromFile(randArray10k, "data/input/10k/inputRandom-10000.txt", 10000);
		readArrayFromFile(ordArray10k, "data/input/10k/inputOrdered-10000.txt", 10000);
		readArrayFromFile(revArray10k, "data/input/10k/inputReversed-10000.txt", 10000);
	} 
	else{
		printf("Memory allocation failed for 10k arrays.\n");
		exit(EXIT_FAILURE);
	}

	//100k
	int *randArray100k = malloc(100000 * sizeof(int));
	int *ordArray100k = malloc(100000 * sizeof(int));
	int *revArray100k = malloc(100000 * sizeof(int));

	if (randArray100k != NULL && ordArray100k != NULL && revArray100k != NULL) {
		readArrayFromFile(randArray100k, "data/input/100k/inputRandom-100000.txt", 100000);
		readArrayFromFile(ordArray100k, "data/input/100k/inputOrdered-100000.txt", 100000);
		readArrayFromFile(revArray100k, "data/input/100k/inputReversed-100000.txt", 100000);
	} else {
		printf("Memory allocation failed for 100k arrays.\n");
		exit(EXIT_FAILURE);
	}

	// 500k
	int *randArray500k = malloc(500000 * sizeof(int));
	int *ordArray500k = malloc(500000 * sizeof(int));
	int *revArray500k = malloc(500000 * sizeof(int));

	if (randArray500k != NULL && ordArray500k != NULL && revArray500k != NULL) {
		readArrayFromFile(randArray500k, "data/input/500k/inputRandom-500000.txt", 500000);
		readArrayFromFile(ordArray500k, "data/input/500k/inputOrdered-500000.txt", 500000);
		readArrayFromFile(revArray500k, "data/input/500k/inputReversed-500000.txt", 500000);
	} else {
		printf("Memory allocation failed for 500k arrays.\n");
		exit(EXIT_FAILURE);
	}

	printf("All arrays generated successfully.\n");
	printf("---x-----x----x-----x-----x-----x---");


	//Selection of the algorithm to test
	int choice = showMenu();

	//benchmarking
	Metric m = createMetric();
	switch(choice){
		case 1:
			// --- 10k ---
			runBubbleSort(randArray10k, 10000, "Random Numbers", "data/output/random/randomSorted-10k.txt", &m);
			runBubbleSort(ordArray10k, 10000, "Ordered Numbers", "data/output/ordered/orderedSorted-10k.txt", &m);
			runBubbleSort(revArray10k, 10000, "Reversed Numbers", "data/output/reversed/reversedSorted-10k.txt", &m);

			// --- 100k ---
			runBubbleSort(randArray100k, 100000, "Random Numbers", "data/output/random/randomSorted-100k.txt", &m);
			runBubbleSort(ordArray100k, 100000, "Ordered Numbers", "data/output/ordered/orderedSorted-100k.txt", &m);
			runBubbleSort(revArray100k, 100000, "Reversed Numbers", "data/output/reversed/reversedSorted-100k.txt", &m);

			// --- 500k ---
			runBubbleSort(randArray500k, 500000, "Random Numbers", "data/output/random/randomSorted-500k.txt", &m);
			runBubbleSort(ordArray500k, 500000, "Ordered Numbers", "data/output/ordered/orderedSorted-500k.txt", &m);
			runBubbleSort(revArray500k, 500000, "Reversed Numbers", "data/output/reversed/reversedSorted-500k.txt", &m);
			break;

		case 2:
			// --- 10k ---
			runBubbleStopSort(randArray10k, 10000, "Random Numbers", "data/output/random/randomSorted-10k.txt", &m);
			runBubbleStopSort(ordArray10k, 10000, "Ordered Numbers", "data/output/ordered/orderedSorted-10k.txt", &m);
			runBubbleStopSort(revArray10k, 10000, "Reversed Numbers", "data/output/reversed/reversedSorted-10k.txt", &m);

			// --- 100k ---
			runBubbleStopSort(randArray100k, 100000, "Random Numbers", "data/output/random/randomSorted-100k.txt", &m);
			runBubbleStopSort(ordArray100k, 100000, "Ordered Numbers", "data/output/ordered/orderedSorted-100k.txt", &m);
			runBubbleStopSort(revArray100k, 100000, "Reversed Numbers", "data/output/reversed/reversedSorted-100k.txt", &m);

			// --- 500k ---
			runBubbleStopSort(randArray500k, 500000, "Random Numbers", "data/output/random/randomSorted-500k.txt", &m);
			runBubbleStopSort(ordArray500k, 500000, "Ordered Numbers", "data/output/ordered/orderedSorted-500k.txt", &m);
			runBubbleStopSort(revArray500k, 500000, "Reversed Numbers", "data/output/reversed/reversedSorted-500k.txt", &m);
			break;
		
		case 3:
			// --- 10k ---
			runInsertionSort(randArray10k, 10000, "Random Numbers", "data/output/random/randomSorted-10k.txt", &m);
			runInsertionSort(ordArray10k, 10000, "Ordered Numbers", "data/output/ordered/orderedSorted-10k.txt", &m);
			runInsertionSort(revArray10k, 10000, "Reversed Numbers", "data/output/reversed/reversedSorted-10k.txt", &m);

			// --- 100k ---
			runInsertionSort(randArray100k, 100000, "Random Numbers", "data/output/random/randomSorted-100k.txt", &m);
			runInsertionSort(ordArray100k, 100000, "Ordered Numbers", "data/output/ordered/orderedSorted-100k.txt", &m);
			runInsertionSort(revArray100k, 100000, "Reversed Numbers", "data/output/reversed/reversedSorted-100k.txt", &m);

			// --- 500k ---
			runInsertionSort(randArray500k, 500000, "Random Numbers", "data/output/random/randomSorted-500k.txt", &m);
			runInsertionSort(ordArray500k, 500000, "Ordered Numbers", "data/output/ordered/orderedSorted-500k.txt", &m);
			runInsertionSort(revArray500k, 500000, "Reversed Numbers", "data/output/reversed/reversedSorted-500k.txt", &m);
			break;

		case 4:
			// --- 10k ---
			runBinarySort(randArray10k, 10000, "Random Numbers", "data/output/random/randomSorted-10k.txt", &m);
			runBinarySort(ordArray10k, 10000, "Ordered Numbers", "data/output/ordered/orderedSorted-10k.txt", &m);
			runBinarySort(revArray10k, 10000, "Reversed Numbers", "data/output/reversed/reversedSorted-10k.txt", &m);

			// --- 100k ---
			runBinarySort(randArray100k, 100000, "Random Numbers", "data/output/random/randomSorted-100k.txt", &m);
			runBinarySort(ordArray100k, 100000, "Ordered Numbers", "data/output/ordered/orderedSorted-100k.txt", &m);
			runBinarySort(revArray100k, 100000, "Reversed Numbers", "data/output/reversed/reversedSorted-100k.txt", &m);

			// --- 500k ---
			runBinarySort(randArray500k, 500000, "Random Numbers", "data/output/random/randomSorted-500k.txt", &m);
			runBinarySort(ordArray500k, 500000, "Ordered Numbers", "data/output/ordered/orderedSorted-500k.txt", &m);
			runBinarySort(revArray500k, 500000, "Reversed Numbers", "data/output/reversed/reversedSorted-500k.txt", &m);
			break;

		case 5: 
			// --- 10k ---
			runTernarySort(randArray10k, 10000, "Random Numbers", "data/output/random/randomSorted-10k.txt", &m);
			runTernarySort(ordArray10k, 10000, "Ordered Numbers", "data/output/ordered/orderedSorted-10k.txt", &m);
			runTernarySort(revArray10k, 10000, "Reversed Numbers", "data/output/reversed/reversedSorted-10k.txt", &m);

			// --- 100k ---
			runTernarySort(randArray100k, 100000, "Random Numbers", "data/output/random/randomSorted-100k.txt", &m);
			runTernarySort(ordArray100k, 100000, "Ordered Numbers", "data/output/ordered/orderedSorted-100k.txt", &m);
			runTernarySort(revArray100k, 100000, "Reversed Numbers", "data/output/reversed/reversedSorted-100k.txt", &m);

			// --- 500k ---
			runTernarySort(randArray500k, 500000, "Random Numbers", "data/output/random/randomSorted-500k.txt", &m);
			runTernarySort(ordArray500k, 500000, "Ordered Numbers", "data/output/ordered/orderedSorted-500k.txt", &m);
			runTernarySort(revArray500k, 500000, "Reversed Numbers", "data/output/reversed/reversedSorted-500k.txt", &m);
			break;

		case 6:
			// --- 10k ---
			runShellSort(randArray10k, 10000, "Random Numbers", "data/output/random/randomSorted-10k.txt", &m);
			runShellSort(ordArray10k, 10000, "Ordered Numbers", "data/output/ordered/orderedSorted-10k.txt", &m);
			runShellSort(revArray10k, 10000, "Reversed Numbers", "data/output/reversed/reversedSorted-10k.txt", &m);

			// --- 100k ---
			runShellSort(randArray100k, 100000, "Random Numbers", "data/output/random/randomSorted-100k.txt", &m);
			runShellSort(ordArray100k, 100000, "Ordered Numbers", "data/output/ordered/orderedSorted-100k.txt", &m);
			runShellSort(revArray100k, 100000, "Reversed Numbers", "data/output/reversed/reversedSorted-100k.txt", &m);

			// --- 500k ---
			runShellSort(randArray500k, 500000, "Random Numbers", "data/output/random/randomSorted-500k.txt", &m);
			runShellSort(ordArray500k, 500000, "Ordered Numbers", "data/output/ordered/orderedSorted-500k.txt", &m);
			runShellSort(revArray500k, 500000, "Reversed Numbers", "data/output/reversed/reversedSorted-500k.txt", &m);
			break;

		case 7:
				// --- 10k ---
			runSelectionSort(randArray10k, 10000, "Random Numbers", "data/output/random/randomSorted-10k.txt", &m);
			runSelectionSort(ordArray10k, 10000, "Ordered Numbers", "data/output/ordered/orderedSorted-10k.txt", &m);
			runSelectionSort(revArray10k, 10000, "Reversed Numbers", "data/output/reversed/reversedSorted-10k.txt", &m);

			// --- 100k ---
			runSelectionSort(randArray100k, 100000, "Random Numbers", "data/output/random/randomSorted-100k.txt", &m);
			runSelectionSort(ordArray100k, 100000, "Ordered Numbers", "data/output/ordered/orderedSorted-100k.txt", &m);
			runSelectionSort(revArray100k, 100000, "Reversed Numbers", "data/output/reversed/reversedSorted-100k.txt", &m);

			// --- 500k ---
			runSelectionSort(randArray500k, 500000, "Random Numbers", "data/output/random/randomSorted-500k.txt", &m);
			runSelectionSort(ordArray500k, 500000, "Ordered Numbers", "data/output/ordered/orderedSorted-500k.txt", &m);
			runSelectionSort(revArray500k, 500000, "Reversed Numbers", "data/output/reversed/reversedSorted-500k.txt", &m);
			break;
		
		case 8:
			// --- 10k ---
			runHeapSort(randArray10k, 10000, "Random Numbers", "data/output/random/randomSorted-10k.txt", &m);
			runHeapSort(ordArray10k, 10000, "Ordered Numbers", "data/output/ordered/orderedSorted-10k.txt", &m);
			runHeapSort(revArray10k, 10000, "Reversed Numbers", "data/output/reversed/reversedSorted-10k.txt", &m);

			// --- 100k ---
			runHeapSort(randArray100k, 100000, "Random Numbers", "data/output/random/randomSorted-100k.txt", &m);
			runHeapSort(ordArray100k, 100000, "Ordered Numbers", "data/output/ordered/orderedSorted-100k.txt", &m);
			runHeapSort(revArray100k, 100000, "Reversed Numbers", "data/output/reversed/reversedSorted-100k.txt", &m);

			// --- 500k ---
			runHeapSort(randArray500k, 500000, "Random Numbers", "data/output/random/randomSorted-500k.txt", &m);
			runHeapSort(ordArray500k, 500000, "Ordered Numbers", "data/output/ordered/orderedSorted-500k.txt", &m);
			runHeapSort(revArray500k, 500000, "Reversed Numbers", "data/output/reversed/reversedSorted-500k.txt", &m);
			break;

		case 9:
			// --- 10k ---
			runQuickSortCenter(randArray10k, 10000, "Random Numbers", "data/output/random/randomSorted-10k.txt", &m);
			runQuickSortCenter(ordArray10k, 10000, "Ordered Numbers", "data/output/ordered/orderedSorted-10k.txt", &m);
			runQuickSortCenter(revArray10k, 10000, "Reversed Numbers", "data/output/reversed/reversedSorted-10k.txt", &m);

			// --- 100k ---
			runQuickSortCenter(randArray100k, 100000, "Random Numbers", "data/output/random/randomSorted-100k.txt", &m);
			runQuickSortCenter(ordArray100k, 100000, "Ordered Numbers", "data/output/ordered/orderedSorted-100k.txt", &m);
			runQuickSortCenter(revArray100k, 100000, "Reversed Numbers", "data/output/reversed/reversedSorted-100k.txt", &m);

			// --- 500k ---
			runQuickSortCenter(randArray500k, 500000, "Random Numbers", "data/output/random/randomSorted-500k.txt", &m);
			runQuickSortCenter(ordArray500k, 500000, "Ordered Numbers", "data/output/ordered/orderedSorted-500k.txt", &m);
			runQuickSortCenter(revArray500k, 500000, "Reversed Numbers", "data/output/reversed/reversedSorted-500k.txt", &m);
			break;

		case 10:
			// --- 10k ---
			runQuickSortMedian(randArray10k, 10000, "Random Numbers", "data/output/random/randomSorted-10k.txt", &m);
			runQuickSortMedian(ordArray10k, 10000, "Ordered Numbers", "data/output/ordered/orderedSorted-10k.txt", &m);
			runQuickSortMedian(revArray10k, 10000, "Reversed Numbers", "data/output/reversed/reversedSorted-10k.txt", &m);

			// --- 100k ---
			runQuickSortMedian(randArray100k, 100000, "Random Numbers", "data/output/random/randomSorted-100k.txt", &m);
			runQuickSortMedian(ordArray100k, 100000, "Ordered Numbers", "data/output/ordered/orderedSorted-100k.txt", &m);
			runQuickSortMedian(revArray100k, 100000, "Reversed Numbers", "data/output/reversed/reversedSorted-100k.txt", &m);

			// --- 500k ---
			runQuickSortMedian(randArray500k, 500000, "Random Numbers", "data/output/random/randomSorted-500k.txt", &m);
			runQuickSortMedian(ordArray500k, 500000, "Ordered Numbers", "data/output/ordered/orderedSorted-500k.txt", &m);
			runQuickSortMedian(revArray500k, 500000, "Reversed Numbers", "data/output/reversed/reversedSorted-500k.txt", &m);
			break;

		case 11:
			// --- 10k ---
			runQuickSortEnd(randArray10k, 10000, "Random Numbers", "data/output/random/randomSorted-10k.txt", &m);
			runQuickSortEnd(ordArray10k, 10000, "Ordered Numbers", "data/output/ordered/orderedSorted-10k.txt", &m);
			runQuickSortEnd(revArray10k, 10000, "Reversed Numbers", "data/output/reversed/reversedSorted-10k.txt", &m);

			// --- 100k ---
			runQuickSortEnd(randArray100k, 100000, "Random Numbers", "data/output/random/randomSorted-100k.txt", &m);
			runQuickSortEnd(ordArray100k, 100000, "Ordered Numbers", "data/output/ordered/orderedSorted-100k.txt", &m);
			runQuickSortEnd(revArray100k, 100000, "Reversed Numbers", "data/output/reversed/reversedSorted-100k.txt", &m);

			// --- 500k ---
			runQuickSortEnd(randArray500k, 500000, "Random Numbers", "data/output/random/randomSorted-500k.txt", &m);
			runQuickSortEnd(ordArray500k, 500000, "Ordered Numbers", "data/output/ordered/orderedSorted-500k.txt", &m);
			runQuickSortEnd(revArray500k, 500000, "Reversed Numbers", "data/output/reversed/reversedSorted-500k.txt", &m);
			break;

		case 12:
			// --- 10k ---
			runMergeSort(randArray10k, 10000, "Random Numbers", "data/output/random/randomSorted-10k.txt", &m);
			runMergeSort(ordArray10k, 10000, "Ordered Numbers", "data/output/ordered/orderedSorted-10k.txt", &m);
			runMergeSort(revArray10k, 10000, "Reversed Numbers", "data/output/reversed/reversedSorted-10k.txt", &m);

			// --- 100k ---
			runMergeSort(randArray100k, 100000, "Random Numbers", "data/output/random/randomSorted-100k.txt", &m);
			runMergeSort(ordArray100k, 100000, "Ordered Numbers", "data/output/ordered/orderedSorted-100k.txt", &m);
			runMergeSort(revArray100k, 100000, "Reversed Numbers", "data/output/reversed/reversedSorted-100k.txt", &m);

			// --- 500k ---
			runMergeSort(randArray500k, 500000, "Random Numbers", "data/output/random/randomSorted-500k.txt", &m);
			runMergeSort(ordArray500k, 500000, "Ordered Numbers", "data/output/ordered/orderedSorted-500k.txt", &m);
			runMergeSort(revArray500k, 500000, "Reversed Numbers", "data/output/reversed/reversedSorted-500k.txt", &m);
			break;

		case 13:
			// --- 10k ---
			runRadixSort(randArray10k, 10000, "Random Numbers", "data/output/random/randomSorted-10k.txt", &m);
			runRadixSort(ordArray10k, 10000, "Ordered Numbers", "data/output/ordered/orderedSorted-10k.txt", &m);
			runRadixSort(revArray10k, 10000, "Reversed Numbers", "data/output/reversed/reversedSorted-10k.txt", &m);

			// --- 100k ---
			runRadixSort(randArray100k, 100000, "Random Numbers", "data/output/random/randomSorted-100k.txt", &m);
			runRadixSort(ordArray100k, 100000, "Ordered Numbers", "data/output/ordered/orderedSorted-100k.txt", &m);
			runRadixSort(revArray100k, 100000, "Reversed Numbers", "data/output/reversed/reversedSorted-100k.txt", &m);

			// --- 500k ---
			runRadixSort(randArray500k, 500000, "Random Numbers", "data/output/random/randomSorted-500k.txt", &m);
			runRadixSort(ordArray500k, 500000, "Ordered Numbers", "data/output/ordered/orderedSorted-500k.txt", &m);
			runRadixSort(revArray500k, 500000, "Reversed Numbers", "data/output/reversed/reversedSorted-500k.txt", &m);
			break;

		case 14:
			// --- 10k ---
			runBucketSort(randArray10k, 10000, "Random Numbers", "data/output/random/randomSorted-10k.txt", &m);
			runBucketSort(ordArray10k, 10000, "Ordered Numbers", "data/output/ordered/orderedSorted-10k.txt", &m);
			runBucketSort(revArray10k, 10000, "Reversed Numbers", "data/output/reversed/reversedSorted-10k.txt", &m);

			// --- 100k ---
			runBucketSort(randArray100k, 100000, "Random Numbers", "data/output/random/randomSorted-100k.txt", &m);
			runBucketSort(ordArray100k, 100000, "Ordered Numbers", "data/output/ordered/orderedSorted-100k.txt", &m);
			runBucketSort(revArray100k, 100000, "Reversed Numbers", "data/output/reversed/reversedSorted-100k.txt", &m);

			// --- 500k ---
			runBucketSort(randArray500k, 500000, "Random Numbers", "data/output/random/randomSorted-500k.txt", &m);
			runBucketSort(ordArray500k, 500000, "Ordered Numbers", "data/output/ordered/orderedSorted-500k.txt", &m);
			runBucketSort(revArray500k, 500000, "Reversed Numbers", "data/output/reversed/reversedSorted-500k.txt", &m);
			break;

	}
	//Free all the arrays
	freeAllArrays(randArray10k, ordArray10k, revArray10k, randArray100k, ordArray100k, revArray100k, randArray500k, ordArray500k, revArray500k);
	
	//Exiting
	showEndMenu();

	return 0;
}
