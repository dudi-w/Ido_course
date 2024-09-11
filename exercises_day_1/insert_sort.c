#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void insertSort(int* arr, size_t size){
    for(size_t i = 1; i < size; ++i){
        int n = arr[i];
        size_t j = i;
        while(j > 0 && arr[j-1] > n){
            arr[j] = arr[j-1];
            --j;
        }
        arr[j] = n;
    }
}
