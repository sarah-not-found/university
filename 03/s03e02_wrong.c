#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int number = 0;
    scanf("%u", &number);
    printf("\n");

    if ((number == 1) || (number == 2)) {
        printf("The number %u is not a perfect number!\n", number);
        return EXIT_SUCCESS;
    }

    unsigned int counter = 0;
    for(unsigned int i = --number; i > 0; i--) {
        if (number % i == 0) {
                counter += i;
        }
    }

    if ((++number == counter) == 1) {
        printf("The number %u is a perfect number!\n", number);
    } else {
        printf("The number %u is not a perfect number!\n", number);
    }
    printf("%u", counter);
    return EXIT_SUCCESS;
}
