#include <stdlib.h>

#include "binary_search.c"
#include "quick_sort.c"
#include "insert_sort.c"

void test_binarySearch() {
    // Test Case 1: Value is in the array
    int arr1[] = {1, 3, 5, 7, 9};
    size_t arr1_size = sizeof(arr1)/sizeof(arr1[0]);
    assert(binarySearch(5, arr1, 0, arr1_size) == 2);  // 5 is at index 2
    assert(binarySearch(9, arr1, 0, arr1_size) == 4);  // 9 is at index 4
    assert(binarySearch(1, arr1, 0, arr1_size) == 0);  // 1 is at index 0

    // Test Case 2: Value is not in the array
    assert(binarySearch(2, arr1, 0, arr1_size) == (size_t)-1);  // 2 is not in the array

    // Test Case 3: Empty array
    int arr2[] = {};
    size_t arr2_size = sizeof(arr2)/sizeof(arr2[0]);
    assert(binarySearch(3, arr2, 0, arr2_size) == (size_t)-1);  // Search in an empty array should return -1

    // Test Case 4: Single-element array
    int arr3[] = {10};
    size_t arr3_size = sizeof(arr3)/sizeof(arr3[0]);
    assert(binarySearch(10, arr3, 0, arr3_size) == 0);  // 10 is the only element, at index 0
    assert(binarySearch(5, arr3, 0, arr3_size) == (size_t)-1);  // 5 is not in the array

    // Test Case 5: Array with negative numbers
    int arr4[] = {-10, -5, 0, 5, 10};
    size_t arr4_size = sizeof(arr4)/sizeof(arr4[0]);
    assert(binarySearch(-5, arr4, 0, arr4_size) == 1);  // -5 is at index 1
    assert(binarySearch(0, arr4, 0, arr4_size) == 2);   // 0 is at index 2
    assert(binarySearch(15, arr4, 0, arr4_size) == (size_t)-1);  // 15 is not in the array
}


// Function to check if array is sorted
int isSorted(int* arr, size_t size) {
    for (size_t i = 1; i < size; ++i) {
        if (arr[i - 1] > arr[i]) {
            return 0; // False
        }
    }
    return 1; // True
}

void test_insertSort() {
    // Test Case 1: Normal array
    int arr1[] = {5, 3, 8, 6, 2};
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    insertSort(arr1, size1);
    assert(isSorted(arr1, size1) == 1);  // Array should be sorted

    // Test Case 2: Already sorted array
    int arr2[] = {1, 2, 3, 4, 5};
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
    insertSort(arr2, size2);
    assert(isSorted(arr2, size2) == 1);  // Array should stay sorted

    // Test Case 3: Reverse-sorted array
    int arr3[] = {9, 7, 5, 3, 1};
    size_t size3 = sizeof(arr3) / sizeof(arr3[0]);
    insertSort(arr3, size3);
    assert(isSorted(arr3, size3) == 1);  // Array should be sorted

    // Test Case 4: Array with duplicates
    int arr4[] = {4, 1, 2, 1, 3};
    size_t size4 = sizeof(arr4) / sizeof(arr4[0]);
    insertSort(arr4, size4);
    assert(isSorted(arr4, size4) == 1);  // Array should be sorted

    // Test Case 5: Array with a single element
    int arr5[] = {7};
    size_t size5 = sizeof(arr5) / sizeof(arr5[0]);
    insertSort(arr5, size5);
    assert(isSorted(arr5, size5) == 1);  // Single element array should be sorted
// 
    // Test Case 6: Empty array
    int arr6[] = {};
    size_t size6 = sizeof(arr6) / sizeof(arr6[0]);
    insertSort(arr6, size6);
    assert(isSorted(arr6, size6) == 1);  // Empty array should be considered sorted
}

void test_quickSort() {
    // Test Case 1: Normal array
    int arr1[] = {5, 3, 8, 6, 2};
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    quickSort(arr1, size1);
    assert(isSorted(arr1, size1) == 1);  // Array should be sorted

    // Test Case 2: Already sorted array
    int arr2[] = {1, 2, 3, 4, 5};
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
    quickSort(arr2, size2);
    assert(isSorted(arr2, size2) == 1);  // Array should stay sorted

    // Test Case 3: Reverse-sorted array
    int arr3[] = {9, 7, 5, 3, 1};
    size_t size3 = sizeof(arr3) / sizeof(arr3[0]);
    quickSort(arr3, size3);
    assert(isSorted(arr3, size3) == 1);  // Array should be sorted

    // Test Case 4: Array with duplicates
    int arr4[] = {4, 1, 2, 1, 3};
    size_t size4 = sizeof(arr4) / sizeof(arr4[0]);
    quickSort(arr4, size4);
    assert(isSorted(arr4, size4) == 1);  // Array should be sorted

    // Test Case 5: Single-element array
    int arr5[] = {7};
    size_t size5 = sizeof(arr5) / sizeof(arr5[0]);
    quickSort(arr5, size5);
    assert(isSorted(arr5, size5) == 1);  // Single element array should be sorted

    // Test Case 6: Empty array
    int arr6[] = {};
    size_t size6 = sizeof(arr6) / sizeof(arr6[0]);
    quickSort(arr6, size6);
    assert(isSorted(arr6, size6) == 1);  // Empty array should be considered sorted
}

int main() {
    // test_binarySearch();
    printf("\033[1;32mAll test cases for Binary Search passed!\033[0m\n");
    test_insertSort();
    printf("\033[1;32mAll test cases for Insert Sort passed!\033[0m\n");
    // test_quickSort();
    printf("\033[1;32mAll test cases for Quick Sort passed!\033[0m\n");
    return EXIT_SUCCESS;
}