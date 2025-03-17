#include <stdio.h>

 int firstOccurrence(int arr[], int n, int key)
 {
 int low = 0, high = n - 1, result = -1; 
while (low <= high)
 {
 int mid = low + (high - low) / 2; 
if (arr[mid] == key) 
{
 result = mid; high = mid - 1; 
 } 
else if (arr[mid] < key)
 { 
low = mid + 1; 
} 
else 
{ 
high = mid - 1;
 } 
}
 return result;
 }

 int lastOccurrence(int arr[], int n, int key)
 { 
int low = 0, high = n - 1, result = -1; 
while (low <= high)
 {
 int mid = low + (high - low) / 2;
 if (arr[mid] == key) 
{
 result = mid; low = mid + 1; 
} 
else if (arr[mid] < key)
 { 
low = mid + 1; 
} 
else 
{
 high = mid - 1; 
} 
}
 return result;
 }

int main() 
{
 int T;
 scanf("%d", &T);
 while (T--) 
{ 
int n, key; 
scanf("%d", &n);
 int arr[n]; 
for (int i = 0; i < n; i++) 
{ 
scanf("%d", &arr[i]);
 } 
scanf("%d", &key);

int first = firstOccurrence(arr, n, key);
    int last = lastOccurrence(arr, n, key);
    
    if (first == -1) {
        printf("Key not present\n");
    } else {
        printf("%d - %d\n", key, (last - first + 1));
    }
}
return 0;
}
