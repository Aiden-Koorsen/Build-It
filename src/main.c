
#include <stdio.h>
#include "parser.h"

int main(int argc, char **argv)
{
	FILE *build_file = NULL;	

	char *file_name;

	if (argc > 2)
	{
		printf("Error: Too many arguments specified\nPlease either enter nno filename or a single filename for the build");
		return 1;
	}
	else
	{
		switch (argc)
		{
			case 1:
				build_file = load_parser("foundation.bif");
				break;

			case 2:
				build_file = load_parser(argv[1]);
				break;
		}
	}
		
	// Check to see if loading was successful
	if (build_file == NULL)
	{
		return 1;
	}

	// If parsing has failed then quit
	if (parse_file(build_file) == 1)
	{
		return 1;
	}

	fclose(build_file);
	return 0;
}

