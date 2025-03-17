#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0, swaps = 0;

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

// Partition function with a random pivot
int partition(int arr[], int low, int high) {
    // Selecting random pivot
    int random = low + rand() % (high - low + 1);
    swap(&arr[random], &arr[high]); // Move pivot to the end
    
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i +