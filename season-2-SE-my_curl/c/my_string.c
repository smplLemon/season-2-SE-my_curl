#include "../h/my_string.h"

int my_strlen(char *p1)
{
    int i = 0;
    while (p1[i] != '\0')
    {
        i++;
    }
    return i;
}

void errorMessage(char *str)
{
    write(2, str, my_strlen(str));
}

char *my_strdup(char *p1)
{
    int size = my_strlen(p1);
    char *str = calloc(sizeof(char), (size + 1));
    fill_null(str, size + 1);
    for (int i = 0; i < size; i++)
    {
        str[i] = p1[i];
    }
    return str;
}

char *my_strcpy(char *str1, char *str2)
{
    for (int i = 0; str2[i]; i++)
    {
        str1[i] = str2[i];
    }
    return str1;
}

char *my_strncpy(char *str1, char *str2, int count)
{
    for (int i = 0; i < count; i++)
    {
        str1[i] = str2[i];
    }
    return str1;
}

int my_strchr(char *str, char c)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == c)
        {
            return i;
        }
    }
    return -1;
}

char *my_strcpy_pro(char *str1, char *str2, char add)
{
    if (add == 0)
    {
        add = ' ';
    }
    int last_i = my_strlen(str1);
    int len2 = my_strlen(str2);
    // int lenForNewStr = last_i + len2 + 1;
    // str1 = realloc(str1, lenForNewStr + 1);
    str1[last_i++] = add;
    for (int i = 0; i < len2; i++)
    {
        str1[last_i++] = str2[i];
    }
    return str1;
}

int my_strcmp(char *p1, char *p2)
{
    for (int i = 0; p1[i] || p2[i]; i++)
    {
        if (p1[i] != p2[i])
        {
            return p1[i] - p2[i];
        }
    }
    return 0;
}

int my_strncmp(char *p1, char *p2, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (p1[i] != p2[i])
        {
            return p1[i] - p2[i];
        }
    }
    return 0;
}

void fill_null(char *str, int size)
{
    for (int i = 0; i < size; i++)
    {
        str[i] = '\0';
    }
}