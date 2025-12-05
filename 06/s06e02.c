#include <stdlib.h>
#include <stdio.h>

/*
 *We may use an unsigned for the function max_difference, because the distance between
 *two integer values will always evaluate to something greater than 0 or zero itself
*/
unsigned max_difference(int values[], size_t length) {
    int smallest_val = values[0];
    int biggest_val = values[0];

    for (int i = length - 1; i >= 0; i--) {
        smallest_val = smallest_val < values[i] ? smallest_val : values[i];
    }
    for (int i = length - 1; i >= 0; i--) {
        biggest_val = biggest_val > values[i] ? biggest_val : values[i];
    }
    return biggest_val - smallest_val;
}

int main(void) {
    int values[] = {1,8,-5,19};
    printf("%u", max_difference(values, sizeof(values)/sizeof(int)));
    return EXIT_SUCCESS;
}
