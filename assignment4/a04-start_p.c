// CS201 Assignment 5: Optimization of a loop.
//
// This is your starting code.  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Submitted code must have the correct values for these two constants:
//    N_TIMES:      200000
//    ARRAY_SIZE:     9973
// Feel free to play with these numbers below during test, 
// but ensure you submit with the correct numbers.
//
#define N_TIMES     200000
#define ARRAY_SIZE    9973

int main (void)
{
    int  *array = calloc(ARRAY_SIZE, sizeof(int));
    int  sum = 0;

	// Declare the following variables for loop unrolling
	int  sum1 = 0;
	int  sum2 = 0;
	int  sum3 = 0;
	int  sum4 = 0;

	int  checksum = 0;
    int  i;
    int  j;
    int  x; 

	int length = ARRAY_SIZE - 11;

    // Make sure you change this so you get credit.
    //
    printf("Jong Seong Lee\n");

    // Initialize the array with random values 0 to 13. 
    //
    srand(time(NULL));
    for (j=0; j < ARRAY_SIZE; j++) {

        x = rand() / (int)(((unsigned)RAND_MAX + 1) / 14);
        array[j] = x;
        checksum += x;
		
    }
	
    //printf("Checksum is %d.\n",checksum);

    for (i = 0; i < N_TIMES; i++) {

        // ---------------------------------------------------------------
        // Do not alter anything above this line, except for the print 
        // statement with your name, and any variables that need to be declared
        // outside of the i loop.  Here is where you make your changes to 
        // optimize performance.  
		
        for (j=0; j < length; j += 12) {
			// Using loop unrolling technique
            sum1 += ((array [j] + array [j+1]) + array [j+2]);
			sum2 += ((array [j+3] + array [j+4]) + array [j+5]);
			sum3 += ((array [j+6] + array [j+7]) + array [j+8]);
			sum4 += ((array [j+9] + array [j+10]) + array [j+11]);
			// printf("Sum is now: %d\n",sum);
        }

		for (; j < ARRAY_SIZE; j++) {
            sum1 += array[j];
		}

		// Collect datas and add everything to sum
		sum = sum1 + sum2 + sum3 + sum4;
		
		// Set the following variables 0
		sum1 = 0;
		sum2 = 0;
		sum3 = 0;
		sum4 = 0;
		
        // Do not alter anything below this line.
        // ---------------------------------------------------------------

        // Check each iteration.  
        //
        
		if (sum != checksum) {
            printf("Checksum error!\n");
        }
		
        sum = 0;

    } 
    return 0;
}