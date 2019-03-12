#include <stdio.h> 
#include <math.h>
#include <stdbool.h>
#define min 1
#define max 99999999999
#define k 8
 
/* 1Á ≈Ò„·Ûﬂ· ¡—«” ‘”…À…÷ŸÕ«” ¡Ã 1115201700170 */ 
 
 
// A function to print all prime factors of a given number n
void primeFactors(int n)
{    
    int i;
     
	 // Print the number of 2s that divide n
    
	while (n%2 == 0)
    
	{
        printf("%d", 2);
        n = n/2;
           //If the number is fully divised ,program stops printing "x"
		   if(n==1) 
                break;
           else
                printf(" x ");
    }
 
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            printf("%d", i);
            n = n/i;
                //If the number is fully divised ,program stops printing "x"
				if(n == 1)
                    break;
                else
                    printf(" x ");
        }
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
    {
		printf ("%d ", n);
    }
}

// A fuction to check every number if it is a MET
bool isMET(int n) 
{
	// In a integer program puts perfect squares
	
	// i is the integer for the iterations
	
	// approximation(interger) helps us find the numbers that
	// that cannot be devised by a square
	
	
	int i, a, apr;
	apr = sqrt(n);
	
	// If the number is 1,2 or 3
	// the function can't work.
	// As a result ,I created a condition to
	// avoid them completely.
	
	if (n == 1 || n == 2 || n == 3) 
   {
	return false;
   }
	// Checking every other positive integer except 1,2 and 3
	// if it is a perfect square(in this condition we find perfect squares)
	if (n % apr == 0) 
	{
	return true;
    }
	// Checking every other positive interger if it can be devised
	// by a perfect square

	for (i=2; i<=apr; i++)
	{
	
	// Program creates the perfect square
	
		a = i*i;
    
	// Then it devises the positive integers except 1,2 and 3(and perfect squares)
    // and checks the mod (for perfect division ==> mod = 0)
	
		if (n % a == 0) 
		{
			return true;
		}		
	}
	// returns false if the number is not MET
	return false; 
}
int main()
{
   int i,temp, count=0; 
	/* meaning of integers */
	
	// k : There we put the desired consequtive MET numbers
    // i : There the program puts every number
    // temp : There the program saves the first of the k consequtive MET numbers
    
	// read the number that forces the program 
	// to show k consequtive MET numbers
	 
	// loop for checking every positive integer
	
	for (i=min; i<=max; i++) 
    
	{   
	    // Checking if i is MET number
    	
		if (isMET(i))  
		{
		// If it is ,program increases count
		
			count ++; 	
		}
	
		// If next i(number) is not MET ,set count to zero
		
		else if (!isMET(i)) 
		{
			count = 0;
		}
		
		// If counter reaches k counts, 
		// set temp the first number
		// of the k consequtive MET numbers
		
		if (count == k) 
		{
		temp = i - (k - 1);
		
		// escape "for"
		
			break;      
	    }
	    
	}
	
	// loop for printing the k consequtive numbers line by line
	
	for(i=1; i<=k; i++)
 
    {    

    printf("%d = ", temp );

   // find the prime factors of every consequtive MET number 

	primeFactors(temp);

	// Change line after every result

	printf("\n"); 

	temp = temp + 1 ;

	}
  
   return 0;
}
		

