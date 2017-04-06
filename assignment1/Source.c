#include "Header.h"


int main (void)
{
	my_bool whileCheck = false;
	
	while (!whileCheck)
	{
		readNumber ();
		whileCheck = endCheck ();
	}

	// End of program
	return 0;
}