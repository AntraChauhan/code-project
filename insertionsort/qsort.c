#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return ((int)a - (int)b);
}

// Function to check for duplicates using sorting
void check_duplicates(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare); // Sorting the array (O(n log n))
    
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
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
        
        check_duplicates(arr, n);
    }
    
    return 0;
}