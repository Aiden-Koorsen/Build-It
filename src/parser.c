#include "parser.h"

int load_parser(FILE *fp, char *file_name)
{
	printf("Build-It: Version 0.01\n");
	// Check to see if file exists and what ever else
	fp = fopen(file_name, "r");
	
	// If file doesn't exist
	if (fp == NULL)
	{
		printf("Error: cannot find file: %s.", file_name);	
		return 1;
	}	
	printf("Build-It: build file has been successfully loaded.\n");
	return 0;	
}

int parse_file(FILE *fp)
{
	// Get line from file
	char line[100];
}
