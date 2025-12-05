#include <stdlib.h>
#include <stdio.h>

unsigned different_bits(unsigned a, unsigned b) {
    unsigned xor_filter = a ^ b;
    unsigned one_counter = 0;

    for (unsigned i = sizeof(xor_filter) * 8; i > 0; --i) {
        if ((xor_filter & 1) == 1) {
            ++one_counter;
        }
        xor_filter = xor_filter >> 1;
    }
    return one_counter;
}

int main(void) {
    unsigned a = 0; unsigned b = 0;
    different_bits(a, b);
    //printf("%u\n", different_bits(a, b));
    return EXIT_SUCCESS;
}
