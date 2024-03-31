#include "../h/my_string.h"

short my_strlen(char* str) {
    short len = 0;
    for(; str[len]; len++);
    return len; 
}

char* my_strdup(char* str) {
    char* src = calloc((my_strlen(str) + 1), sizeof(char));
    for (int i = 0; str[i] != '\0'; i++) {
        src[i] = str[i];
    }
    src[my_strlen(str)] = '\0';
    return src;
}

short my_strcmp(char* str1, char* str2) {
    for(short i = 0; str1[i]; i++) {
        if(str1[i] != str2[i]) return (short)(str1[i]-str2[i]);
    }
    return 0;
}

char* my_strcpy(char* str1, char* str2) {
    for(short i = 0; str2[i]; i++) str1[i] = str2[i];
    return str1;
}

void fill_null(char* str, short over) {
    for (short i = 0; i < over; i++) str[i] = '\0';
}

void error(char* str) {
    write(2, str, my_strlen(str));
    exit(1);
}