
#include <stdio.h>
#include "parser.h"

int main(int argc, char **argv)
{
	FILE *build_file = NULL;	
	int result = 0;

	// Default case when no file name is specified
	if (argc == 1)
	{
		result = load_parser(build_file, "foundation.bif");
	}
	else if (argc == 2)
	{
		// Parse a name as well
		result = load_parser(build_file, argv[1]);
	}
	else if (argc > 2)  
	{
			printf("Error: Too many arguments specified\nPlease either enter nno filename or a single filename for the build");
		return 1;
	}	
	
	if (result != 0)
	{
		
		// We do not print anything here due to use already printing in the load_parser function
		return 1;
	}
	
	// Parse file
	
	return 0;
}

