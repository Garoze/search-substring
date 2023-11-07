#ifndef _AUTOMATA_H
#define _AUTOMATA_H

#include "pattern.h"

struct __automata_t
{
    int size;
    int (*data)[2];
};
typedef struct __automata_t Automata;

Automata* Automata_construct(Pattern* pattern);
Automata* Automata_build(char* string);
int Automata_validate(Automata* automata, char* string);
void Automata_print(Automata* automata);
void Automata_free(Automata* automata);

#endif // _AUTOMATA_H
