#include <bits/stdc++.h>
using namespace std;
 
void swap(long long* a, long long* b)
{
    long long temp = *a;
    *a = *b;
    *b = temp;
}
 
// A utility function to print an array
void printarr(long long a[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}
 
/* This function partitions a[] in three parts
a) a[l..i] contains all elements smaller than pivot
b) a[i+1..j-1] contains all occurrences of pivot
c) a[j..r] contains all elements greater than pivot */
 
// It uses Dutch National Flag Algorithm
void partition(long long a[], int low, int high, int& i, int& j)
{
    // To handle 2 elements
    if (high - low <= 1) {
        if (a[high] < a[low])
            swap(&a[high], &a[low]);
        i = low;
        j = high;
        return;
    }
 
    int mid = low;
    int pivot = a[low];
    while (mid <= high) {
        if (a[mid] < pivot)
            swap(&a[low++], &a[mid++]);
        else if (a[mid] == pivot)
            mid++;
        else if (a[mid] > pivot)
            swap(&a[mid], &a[high--]);
    }
 
    // update i and j
    i = low - 1;
    j = mid; // or high+1
}
 
// 3-way partition based quick sort
void quicksort(long long a[], int low, int high)
{
    if (low >= high) // 1 or 0 elements
        return;
 
    int i, j;
 
    // Note that i and j are passed as reference
    partition(a, low, high, i, j);
 
    // Recur two halves
    quicksort(a, low, i);
    quicksort(a, j, high);
}
 
// Driver Code
int main()
{
    int n;
    cin >> n;
    
    long long arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    // Function Call
    quicksort(arr, 0, n - 1);
    printarr(arr, n);
    return 0;
}