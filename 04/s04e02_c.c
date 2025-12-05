#include <stdio.h>
#include <stdlib.h>

/*
int main(void) {
    int i = 1;
    do {
        if (!(i % 2)) {
            continue;
        }
        printf("%d\n", i);
    } while (i++ < 20);
    return EXIT_SUCCESS;
}
*/

int main(void) {
    int i = 1;
    while (i < 20) {
        if (!(i % 2)) {
            ++i;
            continue;
        }
        printf("%d\n", i);
        ++i;
    }
    return EXIT_SUCCESS;
}
