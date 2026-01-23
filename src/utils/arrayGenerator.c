#include <stdio.h>
#include <stdlib.h>
#include "utils/fileUtils.h"

void genImputRandom(int n, char* fileName){

    int *arr = malloc(n * sizeof(int));
    if(arr != NULL){
        for (int i = 0; i < n; i++) {
            long long r = ((long long)rand() << 31) | rand();
            arr[i] = (int)(r % 1000000000LL);
        }
        sprintf(fileName, "data/input/inputRandom-%d.txt", n);
	    printNumbersToFile(arr, n, fileName);

        free(arr);
    }    
}

void genImputOrdered(int n, char* fileName){

    int *arr = malloc(n * sizeof(int));
    if(arr != NULL){
        for(int i = 0; i < n; i++){
            arr[i] = i;
        }
        char fileName[100];
        sprintf(fileName, "data/input/inputOrdered-%d.txt", n);
	    printNumbersToFile(arr, n, fileName);

        free(arr);
    }
}

void genImputReversed(int n, char* fileName){
    
    int *arr = malloc(n * sizeof(int));
    if(arr != NULL){
        for (int i = 0; i < n; i++) {
            arr[i] = n - 1 - i;
        }

        char fileName[100];
        sprintf(fileName, "data/input/inputReversed-%d.txt", n);
        printNumbersToFile(arr, n, fileName);

        free(arr);
    }
}
