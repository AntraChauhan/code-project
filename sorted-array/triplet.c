#include <stdio.h>

void findTriplet(int arr[], int n) 
{
     for (int k = n - 1; k >= 2; k--) 
     { 
         int i = 0, j = k - 1;
          while (i < j) 
    { 
        int sum = arr[i] + arr[j];
         if (sum == arr[k]) 
         {
             printf("%d, %d, %d\n", i, j, k); return;
             } 
             else if (sum < arr[k])
              { 
                i++; // Increase sum }
                 else {
                     j--;
                      // Decrease sum 
                      }
                       } 
                      } printf("No sequence found.\n"); 
                    }

int main() 
{ 
    int T; 
    scanf("%d", &T);
     while (T--)
      { 
        int n; 
        scanf("%d", &n);
         int arr[n];
          for (int i = 0; i < n; i++) 
          { 
            scanf("%d", &arr[i]); 
        } 
        findTriplet(arr, n); 
    }
         return 
    }