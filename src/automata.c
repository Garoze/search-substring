#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "automata.h"

Automata* Automata_construct(Pattern* pattern)
{
    Automata* automata = calloc(1, sizeof(Automata));
    automata->size = pattern->size;
    automata->data = calloc(pattern->size + 1, sizeof(*automata->data));

    automata->data[0][pattern->pattern[0] - 'a'] = 1;

    for (int i = 1; i < pattern->size; ++i)
    {
        int prev = pattern->table[i - 1];

        for (int j = 0; j < 2; ++j)
        {
            automata->data[i][j] = automata->data[prev][j];
        }

        automata->data[i][pattern->pattern[i] - 'a'] = i + 1;
    }

    for (int i = 0; i < 2; ++i)
    {
        automata->data[pattern->size][i] = pattern->size;
    }

    return automata;
}

int Automata_validate(Automata* automata, char* string)
{
    int state = 0;
    int string_len = strlen(string);

    for (int i = 0; i < string_len; ++i)
    {
        if (state == automata->size)
            return 1;

        state = automata->data[state][string[i] - 'a'];
    }

    return (state == automata->size) ? 1 : 0;
}

void Automata_print(Automata* automata)
{
    for (int i = 0; i < automata->size + 1; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            printf("δ(q%d, '%c') = q%d\n", i, (j + 'a'), automata->data[i][j]);
        }
    }
}

void Automata_free(Automata* automata)
{
    free(automata->data);
    free(automata);
}
