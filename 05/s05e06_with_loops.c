#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/* TODO: Add function(s) */
//Followed by this comment you find the most incopetent and complicated way to solve this... :(
//Just to honor the effort.... here it is
/*
uint32_t print_binary(uint32_t value) {
    short leading_zeros = 0;
    for (short i = 0; i < 32; ++i) { //2147483648 is a 1, followed by 31 0's in binary
        if (value & 2147483648) {
            break;
        }
        ++leading_zeros;
        value = value << 1;
    }
    value = value >> leading_zeros;
    printf("0b%0*d", leading_zeros-1, 0);

    for (short i = 32 - leading_zeros; i > 0; --i) {
        short current_bit = value % 2;
        value = value % 2;
        printf("%u", current_bit);
    } 
    return 5;
}
*/

void print_binary(uint32_t value) {
    printf("0b");
    for (short i = 0; i < 32; ++i) {
        if (value & 0x80000000) { //a one, followed by 31 zeros
            printf("1");
        } else {
            printf("0");
        }
        value = value << 1;
    }
}

int main(void) {
    uint32_t value;
    printf("value: ");
    if (scanf("%"SCNu32, &value) != 1) {
        fprintf(stderr, "ERROR: While reading the 'uint32_t' value an error occurred!");
        return EXIT_FAILURE;
    }
    printf("\n");
    print_binary(value);
    printf("\n");
    return EXIT_SUCCESS;
}
