#ifndef _CURL_H_MY_STRING_H_
#define _CURL_H_MY_STRING_H_

#include <stdlib.h>
#include <unistd.h>

// Counts string length.
short my_strlen(char* str);

// Allocates memory and copy the source.
char* my_strdup(char* str);

// Compares the two string.
short my_strcmp(char* str1, char* str2);

// Copy string to dest.
char* my_strcpy(char* str1, char* str2);

// Stderror message and exit status.
void error(char* str); 

// Fills the '\0' charecters by given length.
void fill_null(char* str, short over);

#endif