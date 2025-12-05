#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned char n = 'a';
    if (scanf("%hhu", &n) == 0) { //scanf must not give out zero, else print error
        fprintf(stderr, "ERROR: The provided input could not be converted!\n");
        return EXIT_FAILURE;
    }
    unsigned int sum = 0; //it's an unsigned 'int', not just a unsigned
    for (unsigned char i = n; i != 0; --i) { //if the condition is >= zero, then this will always be true, because after an unsigned is decremented from 0 it will hop back to it's biggest number
        sum += i;
    }
    printf("sum = %u\n", sum);
    return EXIT_SUCCESS;
}


