// Loading in of files and adding some easy to use string functions for 
// navigation and manipulation of file data

#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* token;

// Each line will contain words which we break up into tokens and store in a chunk
typedef struct
{	
	token* tokens;
	int size;
} token_chunk;

// Token functions
token_chunk generate_tokens(char *line);

// Parser functions
FILE* load_parser(char *file_name);
int parse_file(FILE *fp);

#endif

