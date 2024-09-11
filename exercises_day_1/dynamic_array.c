#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define VAL_INT_MAX 1000

int* allocArray(size_t* size){
    printf("Enter array size: ");
    scanf("%zu", size);
    int* arr = (int*)calloc(*size ,sizeof(int));
    if(arr == NULL){
        exit(0);
    }
    return arr;
}

void fillArrayRandomInt(int* arr, size_t size){
    srand(time(NULL));
    for (size_t i = 0; i < size; ++i){
        arr[i] = rand()%VAL_INT_MAX;
    }
}

int main(int argc, char* argv[]){
    size_t arr_size = 0;
    int* arr = allocArray(&arr_size);
    fillArrayRandomInt(arr, arr_size);
    free(arr);
    return EXIT_SUCCESS;
}
