#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned short n;
    if (/*!*/scanf("%hu", &n) != 1) { //No need for the exclamation mark
        fprintf(stderr, "ERROR: The provided input could not be converted!\n");
        return EXIT_FAILURE;
    }
    unsigned int count = 0; //Should be an unsigned 'int' not just an unsigned
    for (unsigned int /*char*/ i = 0; i < n; ++i) { //We shouldn't use a char, as that will only work for very small numbers
        if (i % 13) {
            ++count;
        }
    }
    printf("count = %u\n", count);
    return EXIT_SUCCESS;
}
