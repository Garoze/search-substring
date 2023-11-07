#include <assert.h>
#include <stdio.h>

#include "automata.h"
#include "pattern.h"

#define DEBUG 1

void test_search_substring()
{
    char* substring = "aaba";

    Automata* automata = Automata_build(substring);

#if DEBUG
    printf("DEBUG: automata -> `%s`\n", substring);
    Automata_print(automata);
    printf("\n");
#endif

    assert(Automata_validate(automata, "bbabb") == 0);
    assert(Automata_validate(automata, "abbabaabbbbaba") == 0);
    assert(Automata_validate(automata, "abaaaaaabab") == 1);
    assert(Automata_validate(automata, "aaaa") == 0);
    assert(Automata_validate(automata, "abba") == 0);
    assert(Automata_validate(automata, "abbb") == 0);
    assert(Automata_validate(automata, "abba") == 0);
    assert(Automata_validate(automata, "baabaab") == 1);
    assert(Automata_validate(automata, "aaba") == 1);
    assert(Automata_validate(automata, "aaabbbbab") == 0);

    Automata_free(automata);

    printf("All tests from `test_search_substring` passed!\n");
}

int main(void)
{
    test_search_substring();

    return 0;
}
