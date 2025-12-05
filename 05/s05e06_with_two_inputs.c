#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/* TODO: Add function(s) */

void print_binary(uint32_t value, short i) {
    if (i == 31) {
        printf("0b");
    }
    if (i >= 0) {
        if (value & 2147483648) {
            printf("1");
        } else {
            printf("0");
        }
    print_binary(value << 1, i - 1);
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
    print_binary(value, 31);
    printf("\n");
    return EXIT_SUCCESS;
}
