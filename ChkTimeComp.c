#include<stdio.h>

// Time complexity O(log(n))
void function_1(int n)
{
	int i, count =0; 

    for(i=1; i<=n; i=2*i) //  O(log(n)) + 1

    //for(i=1; i<n; i=2*i)  //  O(log(n))
     {
 	  count++;
     }
	
	printf("\n function_1 :  count = %d ", count);
	//getch();
}

// Time complexity O(sqrt(n))
void function_2(int n)
{
	int i=1;
	int s=1;
    int count =0; 
	while(s<n)
	{
		count++;
		i++;
		s = s + i;
		
	}
	
	//printf("\n\n function_2 : n = %d ", n);
	//printf("\n function_2 : prev_s = %d ", s-i);
	//printf("\n function_2 : i = %d ", i);
	//printf("\n function_2 : s = %d ", s);
		
	printf("\n function_2 : count = %d ", count);
	//printf("\n\n");
	//getch();
}

//-----------------------------------------------

// Time complexity O(n^2 log(n))
void function_3(int n)
{
	int i, j, k, count =0; 

	for(i=1; i<=n; i++) // O(n)
	{
	 for(j=1; j<=n; j=j+1)  // O(n)
	  {
       for(k=1; k<n; k=k*2) // O(log(n))
  	   {
 		count++;
  	   }
      }
    }
	
	printf("\n function_3 :  count = %d ", count);
	//getch();
}


//-----------------------------------------------

// Time complexity asymptotically O(n^2 log(n))
void function_4(int n)
{
	int i, j, k, count =0; 

	for(i=n/2; i<=n; i++) // Asymptotically O(n) - on actual, runs approx n/2 times
	{
	 for(j=1; j+n/2<=n; j=j+1)  // Asymptotically O(n) - on actual, runs approx n/2 times
	  {
       for(k=1; k<n; k=k*2) // O(log(n))
  	   {
 		count++;
  	   }
      }
    }
	
	printf("\n function_4 :  count = %d ", count);
	//getch();
}

// -------------------------------------------------------------

// Time complexity O(nlog^2(n))
void function_5(int n)
{
	int i, j, k, count =0; 

	for(i=1; i<=n; i++) // Asymptotically O(n) 
	{
	 for(j=1; j<n; j=2*j)  //  O(log(n)) 
	  {
       for(k=1; k<n; k=k*2) // O(log(n))
  	   {
 		count++;
  	   }
      }
    }
	
	printf("\n function_5 :  count = %d ", count);
	//getch();
}

// -------------------------------------------------------------
// -------------------------------------------------------------

// Time complexity O(log^2(n))
void function_6(int n)
{
  int i=1, count=0;
  
  while(i<n) // O(log(n))
  {
   int j=n;
   while (j>1)  // O(log(n))
    {
     count++;
      j=j/2;
    }
   i = 2*i;
  }

  printf("\n function_6 :  count = %d ", count);
  //getch();
}


// ----------------- Main Function -----------------

void main()
{
	
     // O(log(n))
	 function_1(16);

     //O(sqrt(n))
	function_2(9);

    // O(n^2 log(n))
	function_3(8);

    // Asymptotically O(n^2 log(n))
	function_4(8);

	//O(nlog^2(n))
	function_5(8); 

	//O(log^2(n))
	function_6(8); 
	
}
