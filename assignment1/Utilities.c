#include "Header.h"
#include <math.h>

void readNumber ()
{
	int number = 0;
	char read [ARR_MAX];
	char readCheck [ARR_MAX];
	char sum [ARR_MAX];
	unsigned count = 0;
	int bitsCount = BITS_MAX;
			
	// Read a decimal number
	printf ("Enter a decimal number: ");
	scanf ("%s", &read);

	// Check if it is integer
	if (sscanf (read, "%d", &number) == true)
	{
	} else
	{
		printf ("Invalid entry. Please try again.\n\n");
		return;
	}
	
	// Check overflow
	if (!checkOverflow (read, &number))
	{
		printf ("The value you entered is too big or too small. Please try again.\n\n");
		return;
	}
	printf ("You have entered: %d\n\n", number);

	// Check the input and execute binary conversion
	switch (checkNumber (&number))
	{
	case 0:
		// Positive case
		decToBin (sum, number, &bitsCount);
		printf ("Binary representation of %d is: ", number);
		puts (sum);
		break;
	case 1:
		// Negative case
		printf ("Binary representation of %d is: ", number);
		number = negativeNumber (&number, &bitsCount);
		decToBin (sum, number, &bitsCount);
		puts (sum);
		break;
	default:
		// Error
		printf ("Program error. Please try again.\n\n");
		break;
	}	
	
}

void decToBin (char *sum, int number, const int *bitsCount)
{
	int index;
	sum [*bitsCount] = '\0';
	for (index = *bitsCount - 1; index >= 0; --index, number >>= 1)
	{
		sum [index] = (number & 1) + '0';
	}
}

int checkNumber (const int *number)
{
	if (*number <= INT_MAX && *number >= 0)
	{
		// Positive values
		return 0;
	}		
	else if (*number >= INT_MIN && *number < 0)
	{
		// Negative values
		return 1;
	} else
	{
		// TMIN case
		return 2;
	}
}

my_bool endCheck ()
{
	
	my_bool whileLoopControl = false;
	char check;

	// Check if a user wants to end this program
	printf ("Would you like to continue? (y/n): ");

	while (!whileLoopControl)
	{
		check = getchar ();
		
		switch (check)
		{
		case 'y':
			return false;
			break;
		case 'n':
			return true;
			break;
		default:
			break;
		}
	}
}

my_bool checkOverflow (char *read, const int *number)
{
	char readCheck [ARR_MAX];
	int result = 0;

	// Check if the number entered causes overflow
	itoa (*number, readCheck, 10);
	result = strcmp (read, readCheck);

	if (result == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int negativeNumber (int *number, const int *bitsCount)
{
	*number = -*number;

	if (*bitsCount == BITS_MAX)
	{
		return (*number ^ UNSIGNED_MAX) + 1;
	}
	else
	{
		return *number ^ (int) (pow (2.0, *bitsCount) - 1);
	}
}