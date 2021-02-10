
#include <stdio.h>

/* C program implementing the Merge-Sort algorithm */
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void Merge(int Arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    // Create temporary arrays - adding to the space complexity
    // Due to this space overhead, Merge sort is not an inplace algorithm
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = Arr[left + i];

    for (j = 0; j < n2; j++)
        R[j] = Arr[mid + 1 + j];
 
    /* Merge the temp arrays L and R back into Arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) 
	{
        if (L[i] <= R[j]) 
		{
            Arr[k] = L[i];
            i++;
        }
        else 
		{
            Arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1) 
 	 {
        Arr[k] = L[i];
        i++;
        k++;
     }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2) 
	 {
        Arr[k] = R[j];
        j++;
        k++;
     }
}
 
/* left denotes the left-index and right denotes the right-index 
of the sub-array of Arr to be sorted */
void MergeSort(int Arr[], int left, int right)
{
    if (left < right) 
	{
        // Same as (l+r)/2, but avoids overflow for large l and h
        int mid = left + (right - left) / 2;
 
        // Sort the first half
        MergeSort(Arr, left, mid);
 
        // Sort the second half
         MergeSort(Arr, mid + 1, right);
 
        // Combine the two sorted sub-arrays
        Merge(Arr, left, mid, right);
    }
}
 
 
/* Main Function */
void main()
{
    int A[] = {12, 11, 13, 5, 6, 7, 22, 31};
    int i;
    
    int size = sizeof(A) / sizeof(A[0]);
 
    printf("\n Given array is \n");
    for (i = 0; i < size; i++)
        printf(" %d ", A[i]);
    printf("\n");
 
    // Call MergeSort function
    MergeSort(A, 0, size - 1);
 
    printf("\n Sorted array is \n");
    for (i = 0; i < size; i++)
        printf(" %d ", A[i]);
    
}

