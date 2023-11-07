#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pattern.h"

Pattern* Pattern_create(char* string)
{
    Pattern* temp = calloc(1, sizeof(Pattern));
    temp->size = strlen(string);
    temp->pattern = string;
    temp->table = calloc(temp->size, sizeof(int));

    temp->table[0] = 0;

    return temp;
}

Pattern* Pattern_build(char* string)
{
    Pattern* temp = Pattern_create(string);

    int i = 1;
    int j = 0;

    while (i < temp->size)
    {
        if (string[i] == temp->pattern[j])
        {
            temp->table[i++] = ++j;
        }
        else if (j > 0)
        {
            j = temp->table[j - 1];
        }
        else
        {
            temp->table[i++] = 0;
        }
    }

    return temp;
}

void Pattern_free(Pattern* pattern)
{
    free(pattern->table);
    free(pattern);
}

void Pattern_print(Pattern* pattern)
{
    printf("Pattern: `%s` size: %d - ", pattern->pattern, pattern->size);
    printf("Table: [");
    for (int i = 0; i < (pattern->size - 1); ++i)
    {
        printf("%d, ", pattern->table[i]);
    }
    printf("%d ]\n", pattern->pattern[pattern->size]);
}

int Pattern_match(Pattern* pattern, char* string)
{
    int i = 0;
    int len = 0;
    int string_len = strlen(string);

    while (((string_len - i) >= (pattern->size - len)) && len != pattern->size)
    {
        if (pattern->pattern[len] == string[i])
        {
            len++;
            i++;
        }
        else if ((i < string_len) && (len > 0))
        {
            len = pattern->table[len - 1];
        }
        else
        {
            i++;
        }
    }

    return (len == pattern->size) ? (i - len) : -1;
}
