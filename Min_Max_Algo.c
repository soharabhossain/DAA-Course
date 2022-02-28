
#include <stdio.h>

// Let's define a new data type MM_type 
// Variable of this new type will hold/encapsulate two values - min and max
typedef struct minmax_obj
 {
   	 int min;
   	 int max;
 }MM_type;


/* C program implementing the Array MinMax algorithm */
// This function returns 2 values - min and max of a subarray
// This function returns a variable of MM_type which encapsulates the two values - min and max
MM_type MinMaxRecursive(int Arr[], int low, int high)
{
  MM_type mm, mm1, mm2;
  int mid;
  
  // If there is only one element in the array
  if(low==high)
   {
      mm.min=Arr[low];
	  mm.max=Arr[high];
	  return (mm); 
   }
   
  // More than one element 
  if (low<high)
  {
   // Boundary condition	
   if ((high-low)==1)
    {
      if(Arr[low] < Arr[high])
       {
         mm.min=Arr[low];
	  	 mm.max=Arr[high];
	   }
      else
	   {
         mm.min=Arr[high];
	  	 mm.max=Arr[low];
	   }	
     return(mm);
    }
   else
    {
      mid = low + (high - low)/2; // avoid overflow in index calculation for a large array
      //mid = (high + low)/2;     // small input is fine; for large arrays, it may cause numeric overflow
      
      mm1 =  MinMaxRecursive(Arr, low, mid); 
      mm2 =  MinMaxRecursive(Arr, mid+1, high); 

      if(mm1.min < mm2.min)
	   mm.min=mm1.min;
	  else
	   mm.min=mm2.min;

      if(mm1.max > mm2.max)
	   mm.max=mm1.max;
	  else
	   mm.max=mm2.max;
    
	  return(mm);	         	
    }
  }
}
 
 
/* Main Function */
void main()
{
	// Uncomment one of the following lines
	
    int A[] = {12, 11, 13, 5, 6, 7, 66, 100};
    //int A[] = {12, 11, 13, 5, 6, 7, 66};
    //int A[] = {12, 11, 13, 5, 6, 66};
    //int A[] = {12, 13, 5, 66};
    //int A[] = {12};

    MM_type mmg; 	

    int i;
    
    int size = sizeof(A) / sizeof(A[0]);
    printf("\n There are n = %d elements in the array", size);
    
    printf("\n\n The given array is \n");
    for (i = 0; i < size; i++)
        printf(" %d ", A[i]);
    printf("\n");
 
    // Call MinMaxRecursive function
    mmg = MinMaxRecursive(A, 0, size - 1);
 
    printf("\n Array Min = %d ", mmg.min);
    printf("\n Array Max = %d ", mmg.max);
    
}


