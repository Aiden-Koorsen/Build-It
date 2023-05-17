// Loading in of files and adding some easy to use string functions for 
// navigation and manipulation of file data

#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>

typedef char* token;

// Each line will contain words which we break up into tokens and store in a chunk
typedef struct
{	
	token* tokens;	
} token_chunk;
	
FILE* load_parser(char *file_name);
int parse_file(FILE *fp);

#endif

