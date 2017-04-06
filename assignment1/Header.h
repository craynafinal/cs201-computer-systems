#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define UNSIGNED_MAX 4294967295
#define ARR_MAX 33
#define BITS_MAX 32

typedef int my_bool;

void readNumber ();
int checkNumber (const int *number);
void decToBin (char *sum, int number, const int *bitsCount);
int negativeNumber (int *number, const int *bitsCount);
my_bool endCheck ();
my_bool checkOverflow (char *read, const int *number);