#include <stdio.h>

// Function to swap elements at index i and j in an array
void swap(int array[], int i, int j) {
    int temp = array[i];  // Store the value at index i in a temporary variable
    array[i] = array[j];  // Assign the value at index j to index i
    array[j] = temp;      // Assign the value stored in temp to index j
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int length = sizeof(array) / sizeof(array[0]);  // Calculate the length of the array

    // Before swap
    printf("Before swap: ");
    for (int k = 0; k < length; k++) {
        printf("%d ", array[k]);
    }
    printf("\n");

    // Swap elements at index 1 and index 3
    swap(array, 1, 3);

    // After swap
    printf("After swap: ");
    for (int k = 0; k < length; k++) {
        printf("%d ", array[k]);
    }
    printf("\n");

    return 0;
}
