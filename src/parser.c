#include "parser.h"

token_chunk generate_tokens(char *line)
{
	printf("  ->Generating tokens\n");

	int token_count = 0, index = 0;

	// Get amount of spaces
	for (int i = 0; i < strlen(line) - 1; i++)
	{
		if (line[i] == ' ')
		{
			token_count++;
		}
	}

	int space_positions[token_count];

	for (int i = 0; i < strlen(line) - 1; i++)
	{
		if (line[i] == ' ')
		{
			space_positions[index] = i;
			index++;
		}
	}


	token tokens[token_count + 1];

	int offset = 0;

	// Actually extract the tokens
	for (int i = 0; i < token_count; i++)
	{
		int size = 0;
		
		// Get copy size by using the positioning of spaces
		if (i == 0)
		{
			size = space_positions[i];
		}
		else
		{
			size = (space_positions[i] - space_positions[i - 1]) - 1;
		}

		tokens[i] = malloc(sizeof(char) * (size + 1));

		strncpy(tokens[i], (line + offset), size);
		tokens[i][size] = '\0';

		offset = space_positions[i] + 1;
	}

	// Getting the last token from end of file
	int size = (strlen(line) - space_positions[token_count - 1]) - 1;
	tokens[token_count] = malloc(sizeof(char) * (size + 1));

	strncpy(tokens[token_count], (line + strlen(line) - offset), size);
	tokens[token_count][size] = '\0';

	// Assign values to result and then return the new chunk
	token_chunk result;
	
	result.size = token_count + 1;
	result.tokens = tokens;

	
	printf(" there are %i tokens\n", result.size);

	for (int i = 0; i < token_count + 1; i++)
	{
		free(tokens[i]);
	}

	return result;
}

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
		printf("Build file has been successfully loaded.\n");
		
		return fp;
	}
}

int parse_file(FILE *fp)
{
	printf("Parsing build script\n");

	int line_number = 1;
	while (!feof(fp))
	{
		char line[70] = {'\0'};
		token_chunk new_chunk;

		// Gets line from file and ends at newline character - which makes it so we only ever read lines
		if (fgets(line, 70, fp) != NULL)
		{
			// Check if the line is not just blank space
			if (line[0] != '\n')
			{
				// Get tokens and evaluate them
				printf("At Line %i", line_number);
				new_chunk = generate_tokens(line);
				
				
				line_number++;
			}
			else
			{
				line_number++;
			}
		}
		else 
		{
			printf("Error: Failed to parse file at line %i.\n", line_number);
			return 1;
		}
	}	
}
