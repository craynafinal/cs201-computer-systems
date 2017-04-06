#include "Header.h"
#include <math.h>

void readNum (int *num, float *fNum)
{
	int number;
	float fp;
	char read [ARR_MAX];
	char buff [BUFF_MAX];
	my_bool whileControl = TRUE;
	
	while (whileControl == TRUE)
	{
		// Read a number
		printf ("Please enter a number or enter 0 to end this program: ");
		scanf ("%s", &read);
		gets (buff);
		printf ("\n");
		
		// Check if it is a number
		if (sscanf (read, "%d", &number) == TRUE)
		{
			sscanf (read, "%f", &fp);
		} else
		{
			printf ("Invalid entry. Please try again.\n\n");
			return;
		}
		
		// Check overflow
		if (!checkOverflow (read, &number))
		{
			printf ("Your number is out of range. Please try again.\n\n");
		} else {
			whileControl = FALSE;
		}
	}
	// Copy the following variables back to main
	*num = atoi (read);
	*fNum = atof (read); 
}

void performJobs (const int *number, const float *fNum)
{
	// True = Big-endian, False = Small-endian
	my_bool uEndian = endianCheck ();
	my_bool mEndian = machineEndian ();
	int num = *number;
	
	// Use of union
	Uni_data data;
	
	// Integer
	data.intVal = *number;
	printf ("Integer               - Dec: %10d,\tHex: ", num);
	if (uEndian && mEndian)
		// User input: Big-endian, Machine: Big-endian
		print (data);
	else if (uEndian && !mEndian)
		// User input: Big-endian, Machine: Small-endian
		printInverse (data);
	else if (!uEndian && mEndian)
		// User input: Small-endian, Machine: Big-endian
		printInverse (data);
	else if (!uEndian && !mEndian)
		// User input: Small-endian, Machine: Small-endian
		print (data);
	
	// Floating point
	data.fpVal = *fNum;
	printf ("Floating Point Number - Dec: %13.2f,\tHex: ", *fNum);
	if (uEndian && mEndian)
		// User input: Big-endian, Machine: Big-endian
		print (data);
	else if (uEndian && !mEndian)
		// User input: Big-endian, Machine: Small-endian
		printInverse (data);
	else if (!uEndian && mEndian)
		// User input: Small-endian, Machine: Big-endian
		printInverse (data);
	else if (!uEndian && !mEndian)
		// User input: Small-endian, Machine: Small-endian
		print (data);
	printf ("\n");
}

void print (const Uni_data value)
{
	printf ("0X%02X%02X%02X%02X\n", value.string [0], value.string [1], value.string [2], value.string [3]);
}

void printInverse (const Uni_data value)
{
	printf ("0X%02X%02X%02X%02X\n", value.string [3], value.string [2], value.string [1], value.string [0]);
}

int machineEndian()
{
    int testInt = 1;
    char *testChar = (char *)&testInt;

	// Figure out if this machine is Big-endian or Small-endian
    if (testChar[0] == 1)
        return SMALL_ENDIAN;
    else
        return BIG_ENDIAN;
}

my_bool endianCheck ()
{
	char endian = '0';
	char buff [BUFF_MAX];

	// Ask the format user wants
	printf ("Enter 1 (Big-endian format), or 2 (Small-endian format): ");
	scanf ("%c", &endian);
	gets (buff);
	printf ("\n");
	while (endian)
	{
		switch (endian)
		{
		case '1':
			return TRUE;
			break;
		case '2':
			return FALSE;
			break;
		default:
			break;
		}
		printf ("Invalid etry. Enter 1 (Big-endian format), or 2 (Small-endian format): ");
		scanf ("%c", &endian);
		gets (buff);
		printf ("\n");
	}
}

my_bool checkOverflow (const char *read, const int *number)
{
	char checkInt [ARR_MAX];
	int index = 0;
	my_bool result = TRUE;
	
	// Check if the number causes overflow
	itoa (*number, checkInt, 10);
	
	for (index; index < (strlen (checkInt)); index ++)
	{
		if (checkInt [index] != read [index])
			result = FALSE;
	}
		
	if (result == TRUE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}