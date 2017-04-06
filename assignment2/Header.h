#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define INTEGER_MIN -2147483648
#define ARR_MAX 33
#define BUFF_MAX 101
#define BITS_MAX 32
#define SMALL_ENDIAN 0
#define BIG_ENDIAN    1

typedef int my_bool;

// For conversion between float and unsigned char
typedef union
{
	float fpVal;
	int intVal;
	unsigned char string [4];
} Uni_data;

my_bool checkOverflow (const char *read, const int *number);
void performJobs (const int *number, const float *fNum);
void readNum (int *num, float *fNum);
my_bool endianCheck ();
int machineEndian();
void print (const Uni_data value);
void printInverse (const Uni_data value);