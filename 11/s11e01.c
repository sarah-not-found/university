#include "my_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


my_list *compute_solutions(unsigned short max_digit);


int main(void) {
    unsigned short max_digit = 9;

    my_list *solutions = compute_solutions(max_digit);

    for (size_t i = 0; i < my_list_size(solutions); i++) {
        char *solution = my_list_get(solutions, i);
        printf("Solution %zu: %s\n", i + 1, solution);
        free(solution);
    }

    my_list_free(solutions);

    return EXIT_SUCCESS;
}
