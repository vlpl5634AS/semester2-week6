#include <stdio.h>

void bubbleSort(int array[], int n);

int main(void) {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Before sorting: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  bubbleSort(arr, n);

  printf("After sorting: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

/**
 * @brief Sorts an array of integers in ascending order using the bubble sort algorithm.
 * 
 * @param arr The array of integers to be sorted.
 * @param n The number of elements in the array.
 */
void bubbleSort(int array[], int n) {
  // code goes here
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        // Swap array[j] and array[j+1]
        int temp = array[j]; // Store the current element in a temporary variable
        array[j] = array[j + 1]; // Assign the next element to the current position
        array[j + 1] = temp; // Assign the original current element (stored in temp) to the next position
      }
    }
  }
}