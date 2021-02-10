// Iterative Binary Search Algorithm
int BinarySearchIterative(int A[], int n, int key)
{
 int low = 0;
 int high = n-1;
 int mid;
 while (low <= high)
  {
   //mid = low + (high-low)/2; //To avoid overflow
   mid = (high+low)/2; //May overflow for a big array

   if (A[mid] == key)
     return mid;
   else if (A[mid] < key)
          low = mid + 1;
        else
          high = mid - 1;
 }
 return -1;
}


// Recursive Binary Search Algorithm
int BinarySearchRecursive (int A[], int low, int high, int key)
{
 if(high>=low)
  {
 	
   int mid = low + (high-low)/2; //To avoid overflow
       //mid = (low+high)/2;
   if (A[mid] == key)
     return mid;
   else if (A[mid] < key)
         return BinarySearchRecursive (A, mid + 1, high, key);
        else
         return BinarySearchRecursive (A, low, mid - 1 , key);
  }
 return -1;
}


void main()
{
	int A[] = {4, 6, 8, 9, 12, 23, 112, 221, 330, 400};
	int i, n, idx=0, k;
		
	idx=0;
	
    n = sizeof(A)/sizeof(A[0]);
	printf("\n There are n = %d elements in the array", n);

    printf("\n\n The array is : \n");
    for(i=0;i<n;i++)
	 printf(" %d ", A[i]);	

    printf("\n\n Enter the key you are searching for : ");
    scanf("%d", &k);	

    // Function call - Iterative Binary Search
	//idx = BinarySearchIterative(A, n, k);

    // Function call - Recursive Binary Search
	idx = BinarySearchRecursive(A, 0, n, k);
	
	if (idx==-1)
	 printf("\n\n The key %d is not found in the array.", k);
	else
	 printf("\n\n The key %d is found at index %d", k, idx);
	
}
