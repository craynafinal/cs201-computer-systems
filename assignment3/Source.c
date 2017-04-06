#include <stdio.h>
#include <math.h>


#define LINEMAX 33

double absD (double n);

int main ()
{
	int whileControl = 1;
	double n = 0;
	char buf [LINEMAX];
	
	
	while (whileControl != 0)
	{
		printf ("Please enter a number to change into an absolute value or enter 0 to end this program: ");

		fgets (buf, LINEMAX, stdin);
		n = atof (buf);

		// Check if it is a number
		if (n == 0)
		{
			whileControl = 0;	

		// Check for NaN
		} else if ((n != n) == 0)
		{
			whileControl = 0;
		} else
		{
			printf ("The value is: %.2lf\n\n", absD (n));
		}
	}
	
	printf ("\nGoodbye!");
	getchar ();

	return 0;
}

double absD (double n)
{
	double num;
	
	_asm
	{
		fld n;			; Load the argument
		fabs			; Convert into the absolute value
		fst num;		; Save the result in the local variable
	}
	
	return num;
}