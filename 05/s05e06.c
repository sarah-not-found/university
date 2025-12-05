#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/* TODO: Add function(s) */

void print_binary(uint32_t value) {
  /*int 1 = 31;
    printf("%d",((value >> bit_position) & 1));
    print_binary(value << 1);*/
    
    printf("%d", (value >> 31) & 1);
    printf("%d", (value >> 30) & 1);
    printf("%d", (value >> 29) & 1);
    printf("%d", (value >> 28) & 1);
    printf("%d", (value >> 27) & 1);
    printf("%d", (value >> 26) & 1);
    printf("%d", (value >> 25) & 1);
    printf("%d", (value >> 24) & 1);
    printf("%d", (value >> 23) & 1);
    printf("%d", (value >> 22) & 1);
    printf("%d", (value >> 21) & 1);
    printf("%d", (value >> 20) & 1);
    printf("%d", (value >> 19) & 1);
    printf("%d", (value >> 18) & 1);
    printf("%d", (value >> 17) & 1);
    printf("%d", (value >> 16) & 1);
    printf("%d", (value >> 15) & 1);
    printf("%d", (value >> 14) & 1);
    printf("%d", (value >> 13) & 1);
    printf("%d", (value >> 12) & 1);
    printf("%d", (value >> 11) & 1);
    printf("%d", (value >> 10) & 1);
    printf("%d", (value >> 9) & 1);
    printf("%d", (value >> 8) & 1);
    printf("%d", (value >> 7) & 1);
    printf("%d", (value >> 6) & 1);
    printf("%d", (value >> 5) & 1);
    printf("%d", (value >> 4) & 1);
    printf("%d", (value >> 3) & 1);
    printf("%d", (value >> 2) & 1);
    printf("%d", (value >> 1) & 1);
    printf("%d", value & 1);
}

int main(void) {
    uint32_t value;
    printf("value: ");
    if (scanf("%"SCNu32, &value) != 1) {
        fprintf(stderr, "ERROR: While reading the 'uint32_t' value an error occurred!");
        return EXIT_FAILURE;
    }
    printf("\n");
    printf("%" PRIu32, value);
    printf(" = 0b");
    print_binary(value);
    printf("\n");
    return EXIT_SUCCESS;
}
