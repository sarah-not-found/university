
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


void test_list(unsigned long long a, unsigned long long b) {

    printf("number of digits: %zu\n", );
    printf("digit sum: %llu\n", );
    printf("highest digit: %d\n", );


    printf("%llu + %llu = ", a, b);
    print_uint_list(list_c);

    // free resources
}


int main(void) {
    test_list(25, 17);
    printf("\n\n");
    test_list(987, 14);
    printf("\n\n");
    test_list(ULLONG_MAX, 10);
    printf("\ncomputing ULLONG_MAX + 10 without list: %llu", ULLONG_MAX + 10);

    return EXIT_SUCCESS;
}
