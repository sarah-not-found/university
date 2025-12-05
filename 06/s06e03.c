#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

size_t count_number_of_letters(char text[]) {
    size_t counter = 0;
    const char latinAlpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unsigned lengthLatinAlpha = sizeof(latinAlpha)/sizeof(char);
    unsigned lengthText = strlen(text); //Two ways of receiving the length of a string/array

    for (unsigned i = 0; i < lengthText; i++) {
        for (unsigned j = 0; j < lengthLatinAlpha; j++) {
            if (text[i] == latinAlpha[j] || text[i] == tolower(latinAlpha[j])) {
                counter++;
            }
        }
    }
    return counter;
}

int main(void) {
    char text[] = "";
    printf("%lu\n", count_number_of_letters(text));
    return EXIT_SUCCESS;
}
