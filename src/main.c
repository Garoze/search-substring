#include <stdio.h>

#include "automata.h"
#include "pattern.h"

void test_search_substring()
{
    char* substring = "aaba";

    Pattern* pattern = Pattern_build(substring);
    Automata* automata = Automata_construct(pattern);

    printf("%d\n", Automata_validate(automata, "bbabb"));
    printf("%d\n", Automata_validate(automata, "abbabaabbbbaba"));
    printf("%d\n", Automata_validate(automata, "abaaaaaabab"));
    printf("%d\n", Automata_validate(automata, "aaaa"));
    printf("%d\n", Automata_validate(automata, "abba"));
    printf("%d\n", Automata_validate(automata, "abbb"));
    printf("%d\n", Automata_validate(automata, "abba"));
    printf("%d\n", Automata_validate(automata, "baabaab"));
    printf("%d\n", Automata_validate(automata, "aaba"));
    printf("%d\n", Automata_validate(automata, "aaabbbbab"));

    Pattern_free(pattern);
    Automata_free(automata);
}

int main(void)
{
    test_search_substring();

    return 0;
}
