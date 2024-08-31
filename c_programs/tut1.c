#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int readArray(int [], int);
void printArray(int [], int);
void reverseArrayRecursive(int [], int);
void reverseArrayIterative(int [], int);
void swap(int [], int, int);
void recursionHelper(int [], int, int);
void reverseArrayRecursive2(int [], int);
int* reverseArrayRecursiveHelper2(int [], int, int);
void copyArray(int*, int*, int);
int main(){
    int array[MAX], numElements;
    numElements = readArray(array, MAX);
    reverseArrayRecursive2(array, numElements);
    
    printArray(array, numElements);
    return 0;
}

int readArray(int arr[], int limit) {
    printf("Enter up to %d integers, terminating with a negative integer.\n", limit);
    int i;
    for (i = 0; i < limit; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp < 0) {
            return i;
        }
        arr[i] = tmp;
    }
    return limit;
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}
void reverseArrayRecursive(int arr[], int size) {
    recursionHelper(arr, 0, size);
}

void reverseArrayRecursive2(int arr[], int size) {
    copyArray(reverseArrayRecursiveHelper2(arr, 0, size), arr, size);
}

void recursionHelper(int arr[], int start, int end) {
    if (start >= end) {
        return;  
    }
    swap(arr, start, end);
    recursionHelper(arr, start + 1, end - 1);
}

void reverseArrayIterative(int arr[], int size) {
    int i;
    for (i = 0; i < size / 2; i++) {
        int tmp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = tmp;
    }
}

void swap(int arr[], int idx1, int idx2) {
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}


int* reverseArrayRecursiveHelper2(int arr[], int start, int end) {
    if (start >= end) {
        int* baseArr = (int*)malloc((end - start + 1) * sizeof(int));
        if (end - start >= 0) {
            baseArr[0] = arr[start];
        }
        return baseArr;
    }
    int mid = start + (end - start) / 2;
    int leftSize = mid - start + 1;
    int rightSize = end - mid;  
    int* leftReversed = reverseArrayRecursiveHelper2(arr, start, mid);
    int* rightReversed = reverseArrayRecursiveHelper2(arr, mid + 1, end);
    int* combined = (int*)malloc((end - start + 1) * sizeof(int));
    for (int i = 0; i < rightSize; i++) { 
        combined[i] = rightReversed[i];
    }
    for (int i = 0; i < leftSize; i++) {
        combined[rightSize + i] = leftReversed[i];
    }
    free(leftReversed);
    free(rightReversed);
    return combined;
}

void copyArray(int* src, int* dest, int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}
