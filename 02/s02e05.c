#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int number;
    if (scanf("%d", &number) != 1) {
        printf("ERROR: While reading the 'int' value an error occurred!");
        return EXIT_FAILURE;
    }
    printf("%d\n", number);
    return EXIT_SUCCESS;
}
