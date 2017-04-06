#include "Header.h"

int main (void)
{
	int num = 1;
	float fp;

	// Read a number and check for errors
	readNum (&num, &fp);
	
	while (num != 0)
	{
		// Start converting jobs
		performJobs(&num, &fp);
		readNum (&num, &fp);
	}
	
	// End of program
	printf ("Goodbye!\n");
	getchar();
	return 0;
}