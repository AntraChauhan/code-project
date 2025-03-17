#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (similar to QuickSort)
int partition(int arr[], int low, int high, int pivot) {
    int i, j;
    for (i = low; i < high; i++) {
        if (arr[i] == pivot) {
            swap(&arr[i], &arr[high]);
            break;
        }
    }
    
    i = low;
    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

// Function to find median of a small array
int findMedian(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
    return arr[n/2];
}

// Median of Medians function
int selectPivot(int arr[], int low, int high) {
    int n = high - low + 1;
    if (n <= 5) {
        return findMedian(arr + low, n);
    }

    int numMedians = (n + 4) / 5;
    int medians[numMedians];

    for (int i = 0; i < numMedians; i++) {
        int subSize = (i * 5 + 5 <= n) ? 5 : (n % 5);
        medians[i] = findMedian(arr + low + i * 5, subSize);
    }

    return selectPivot(medians, 0, numMedians - 1);
}

// QuickSelect function to find the Kth smallest element
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivot = selectPivot(arr, low, high);
        int partitionIndex = partition(arr, low, high, pivot);

        if (partitionIndex == k) {
            return arr[partitionIndex];
        } else if (partitionIndex > k) {
            return quickSelect(arr, low, partitionIndex - 1, k);
        } else {
            return quickSelect(arr, partitionIndex + 1, high, k);
        }
    }
    return INT_MAX;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, k;
        scanf("%d", &n);
        int arr[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        scanf("%d", &k);

        if (k < 1 || k > n) {
            printf("not present\n");
        } else {
            int result = quickSelect(arr, 0, n - 1, k - 1);
            printf("%d\n", result);
        }
    }

    return 0;
}