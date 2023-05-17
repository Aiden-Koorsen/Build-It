#include "parser.h"

FILE* load_parser(char *file_name)
{
	printf("Build-It: Version 0.01\n");
	// Check to see if file exists and what ever else
	FILE *fp = fopen(file_name, "r");
	
	// If file doesn't exist
	if (ferror(fp) || fp == NULL)
	{
		printf("Error: File has failed to open%s.\n", file_name);	
		return NULL;
	}
	else
	{
		printf("Build-It: build file has been successfully loaded.\n");
		
		return fp;
	}
}

int parse_file(FILE *fp)
{
	printf("Build-It: Now parsing build script\n");

	// Get line from file
	char line[5];
	
	if (fgets(line, 5, fp) != NULL)
	{
		printf("%s\n", line);
		return 0;
	}
	else
	{
		printf("Error: Failed to read from file.\n");
		return 1;
	}
}
