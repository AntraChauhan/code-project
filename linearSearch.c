#include <stdio.h>
#include <math.h>

void jumpSearch(int arr[], int n, int key) {
    int step = sqrt(n);
    int prev = 0, comparisons = 0;

    // Finding the block where the element might be present
    while (prev < n && arr[prev] < key) {
        comparisons++;
        if (prev + step >= n)  // Prevent out-of-bounds access
            break;
        prev += step;
    }

    // Adjusting the range for linear search
    int start = prev - step;  // Move back to the beginning of the block
    if (start < 0) start = 0; // Ensure it's within bounds

    // Linear search within the block
    for (int i = start; i < n && i < prev + step; i++) {
        comparisons++;
        if (arr[i] == key) {
            printf("Present %d\n", comparisons);
            return;
        }
    }

    printf("Not Present %d\n", comparisons);
}

int main() {
    int t;
    scanf("%d", &t);  // Number of test cases

    while (t--) {
        int n, key;
        scanf("%d", &n);  // Size of the array

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        scanf("%d", &key);  // Element to search

        jumpSearch(arr, n, key);
    }

    return 0;
}
