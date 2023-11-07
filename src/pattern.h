#ifndef _PATTERN_H
#define _PATTERN_H

struct __prefix_table_t
{
    int size;
    int* table;
    char* pattern;
};
typedef struct __prefix_table_t Pattern;

Pattern* Pattern_create(char* string);
Pattern* Pattern_build(char* string);

void Pattern_free(Pattern* pattern);
void Pattern_print(Pattern* pattern);

#endif // _PATTERN_H
