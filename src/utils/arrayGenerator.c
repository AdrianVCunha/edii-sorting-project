#include <stdio.h>
#include <stdlib.h>
#include "utils/fileUtils.h"

char* getImputDir(int n){
    switch(n){
        case 10000: return "10k";
        case 100000: return "100k";
        case 500000: return "500k";
        default: return "Invalid";
    }
}

void genImputRandom(int n){

    int *arr = malloc(n * sizeof(int));
    if(arr != NULL){
        for (int i = 0; i < n; i++) {
            long long r = ((long long)rand() << 31) | rand();
            arr[i] = (int)(r % 1000000000LL);
        }
        char fileName[100];
        sprintf(fileName, "data/input/%s/inputRandom-%d.txt", getImputDir(n), n);
	    printNumbersToFile(arr, n, fileName);

        free(arr);
    }    
}

void genImputOrdered(int n){

    int *arr = malloc(n * sizeof(int));
    if(arr != NULL){
        for(int i = 0; i < n; i++){
            arr[i] = i;
        }
        char fileName[100];
        sprintf(fileName, "data/input/%s/inputOrdered-%d.txt", getImputDir(n), n);
	    printNumbersToFile(arr, n, fileName);

        free(arr);
    }
}

void genImputReversed(int n){
    
    int *arr = malloc(n * sizeof(int));
    if(arr != NULL){
        for (int i = 0; i < n; i++) {
            arr[i] = n - 1 - i;
        }

        char fileName[100];
        sprintf(fileName, "data/input/%s/inputReversed-%d.txt", getImputDir(n), n);
        printNumbersToFile(arr, n, fileName);

        free(arr);
    }
}

void genAllImputs(){
    int sizes[] = {10000, 100000, 500000};
    for(int i = 0; i < 3; i++){
        int n = sizes[i];
        genImputRandom(n);
        genImputOrdered(n);
        genImputReversed(n);
    }
}

