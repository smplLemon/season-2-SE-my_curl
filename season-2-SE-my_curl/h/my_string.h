#ifndef MY_CURL_H_MY_STRING_H_
#define MY_CURL_H_MY_STRING_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int my_strlen(char *);
void errorMessage(char *str);
int my_strcmp(char *, char *);
int my_strncmp(char *p1, char *p2, int size);
char *my_strcpy(char *str1, char *str2);
char *my_strncpy(char *str1, char *str2, int count);
int my_strchr(char *str, char c);
char *my_strcpy_pro(char *str1, char *str2, char add);
char *my_strdup(char *);
void fill_null(char *, int);

#endif