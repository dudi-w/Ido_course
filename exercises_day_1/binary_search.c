#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include <assert.h>

size_t binarySearch(int val, int* arr, size_t begin, size_t end){
    size_t arr_size = end - begin;
    size_t h = begin + (arr_size/2);
    
    if(arr_size == 0){
        return -1;
    }
    if(arr[h] == val){
        return h;
    }
    if(arr[h] > val){
        size_t i = binarySearch(val, arr, begin, h);
        if(i != -1){
            return i;
        }
    }
    if(arr[h] < val){
        size_t i = binarySearch(val, arr, h+1, end);
        if(i != -1){
            return i;
        }
    }
    return -1;
}