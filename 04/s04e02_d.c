#include <stdio.h>
#include <stdlib.h>

/*
int main(void) {
    unsigned height = 10;
    unsigned i = 1;
    unsigned j = 1;
    while (i <= height) {
        while (j <= height) {
            printf(" %c", height - j++ >= i ? ' ' : '#');
        }
        printf("\n");
        i += 3;
        j = 1;
    }
    return EXIT_SUCCESS;
}
*/

int main(void) {
    unsigned height = 10;

    for (unsigned i = 1; i <= height; i += 3) {
        for (unsigned j = 1; j <= height; j++) {
            printf(" %c", height - j >= i ? ' ' : '#');
        }
        printf("\n");
    }
}

