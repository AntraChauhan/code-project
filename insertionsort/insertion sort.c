#include <stdio.h>

void insertion_sort(int arr[], int n, int *comparisons, int *shifts) {
    *comparisons = 0;
    *shifts = 0;
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            (*comparisons)++; // Each while loop condition check is a comparison
            arr[j + 1] = arr[j]; // Shift operation
            (*shifts)++;
            j--;
        }
        arr[j + 1] = key; // Placing key in its correct position
        (*shifts)++; // This is also considered as a shift
        
        if (j >= 0) {
            (*comparisons)++; // One additional comparison when while loop breaks
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        int comparisons = 0, shifts = 0;
        insertion_sort(arr, n, &comparisons, &shifts);
        
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\ncomparisons = %d\n", comparisons);
        printf("shifts = %d\n", shifts);
    }
    
    return 0;
}