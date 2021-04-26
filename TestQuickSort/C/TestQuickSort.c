//TestQuickSort.c
//24/03/2021
#include <stdio.h>

// swap(a, b)
// Description: This function swap the position of elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// partition(array, low, high)
// Description: This function part the array on the basis of pivot element
int partition(int array[], int low, int high) {
  
  // Select the pivot element
  int pivot = array[high];
  int i = (low - 1);

  // Put the elements smaller than pivot on the left 
  // and greater than pivot on the right of pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

// quickSort(array, low, high)
// Description: This function sort an array using the quick sort algorithm
void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // Select pivot position and put all the elements smaller 
    // than pivot on left and greater than pivot on right
    int pi = partition(array, low, high);
    
    // Sort the elements on the left of pivot
    quickSort(array, low, pi - 1);
    
    // Sort the elements on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

int main() {
  int data[] = {8, 7, 2, 1, 0, 9, 6};
  int dataSize = sizeof(data) / sizeof(data[0]);
  quickSort(data, 0, dataSize - 1);
  
  // Print sorted array
  for (int i = 0; i < dataSize; ++i) {
    printf("%d  ", data[i]);
  }
  
}