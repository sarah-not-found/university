#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //Preparation
    unsigned int number = 0;
    scanf("%u", &number);
    printf("\n");

    //Logic
    unsigned int counter = 0;
    for (int i = number - 1; i > 0; i--) {
        if ((number % i) == 0) {
            counter += i;
        }
    }

    //Output
    if (number == counter) {
        printf("The number %u is a perfect number!\n", number);
    } else {
        printf("The number %u is not a perfect number!\n", number);
    }
    return EXIT_SUCCESS;
    //printf("%u\n", counter);
}