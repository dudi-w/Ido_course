#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

size_t partition(int* arr, size_t i, size_t j){
    int pivot = arr[i];
    size_t t = i++;
    while(i < j){
        if(arr[i] > pivot){
            swap(&arr[--j], &arr[i]);
        }else{
            ++i;
        }
    }
    swap(&arr[--i], &arr[t]);
    return i;
}

void sort(int* arr, size_t begin, size_t end){
    if(begin < end){
        size_t pivot = partition(arr, begin, end);
        sort(arr, begin, pivot);
        sort(arr, pivot+1, end);
    }
}

void quickSort(int* arr, size_t size){
    sort(arr,0,size);
    return;
}
