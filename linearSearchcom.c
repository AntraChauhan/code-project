#include <stdio.h>
#include<math.h>

void jumpSearch(int arr[], int n, int key) 
{ 
    int step = sqrt(n); int prev = 0, comparisons = 0;

// Finding the block where the element might be present
while (arr[(prev + step < n) ? prev + step : n - 1] < key)
 {
    comparisons++;
    prev += step;
    if (prev >= n) {
        printf("Not Present %d\n", comparisons);
        return;
    }
}

// Linear search within the block
for (int i = prev; i < n && i <= prev + step; i++)
 {
    comparisons++;
    if (arr[i] == key) {
        printf("Present %d\n", comparisons);
        return;
    }
}

printf("Not Present %d\n", comparisons);

}

int main() { int t; scanf("%d", &t);  // Number of test cases

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