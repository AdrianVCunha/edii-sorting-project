#include <stdio.h>

int showMenu(){
    int n;
    printf("\n\n====================================\n");
	printf("   Sorting Algorithm Benchmark\n");
	printf("====================================\n");
	printf("Choose an algorithm to test\n");
	printf("(-1 to exit)\n\n");
	printf(" 1  - Bubble Sort\n");
	printf(" 2  - Bubble Sort (Early Stop)\n");
	printf(" 3  - Insertion Sort\n");
	printf(" 4  - Binary Insertion Sort\n");
	printf(" 5  - Ternary Insertion Sort\n\n");
	printf(" 6  - Shell Sort\n");
	printf(" 7  - Selection Sort\n");
	printf(" 8  - Heap Sort\n\n");
	printf(" 9  - Quick Sort (Center Pivot)\n");
	printf("10  - Quick Sort (Mean Pivot)\n");
	printf("11  - Quick Sort (End Pivot)\n\n");
	printf("12  - Merge Sort\n");
	printf("13  - Radix Sort\n");
	printf("14  - Bucket Sort\n");

	printf("\nYour choice: ");
    scanf("%d", &n);
     int c;
    while ((c = getchar()) != '\n' && c != EOF); 
    return n;
}

void showEndMenu() {
    printf("\n\n====================================\n");
    printf("        Benchmark Completed!        \n");
    printf("====================================\n");
    printf("All selected algorithms have finished running.\n");
    printf("Output files and metrics have been saved in the respective folders.\n\n");
    printf("Press ENTER to exit...");
    getchar();  
}
