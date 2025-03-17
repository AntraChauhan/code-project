#include <stdio.h>

void selection_sort(int arr[], int n, int *comparisons, int *swaps) {
    *comparisons = 0;
    *swaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            (*comparisons)++; // Each comparison in the inner loop
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            (*swaps)++; // Counting swaps
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
        
        int comparisons = 0, swaps = 0;
        selection_sort(arr, n, &comparisons, &swaps);
        
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\ncomparisons = %d\n", comparisons);
        printf("swaps = %d\n", swaps);
    }
    
    return 0;
}