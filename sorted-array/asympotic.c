#include <stdio.h>
#include <time.h>

// Function to demonstrate asymptotic notation
double measure_time(void (*func)(int[], int), int arr[], int n) {
    clock_t start, end;
    start = clock();
    func(arr, n);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Linear Search
int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search (Array should be sorted)
int binary_search(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Bubble Sort
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Quick Sort
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high], i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 22;

    printf("Linear Search: Element found at index %d\n", linear_search(arr, n, key));

    bubble_sort(arr, n);
    printf("Binary Search: Element found at index %d\n", binary_search(arr, 0, n - 1, key));

    int arr2[] = {64, 25, 12, 22, 11};
    printf("Time for Bubble Sort: %f sec\n", measure_time(bubble_sort, arr2, n));

    return 0;
}