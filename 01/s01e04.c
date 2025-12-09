//
// Created by sarah on 09/12/2025.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_altering(int result[],
                    const int a[], size_t len_a,
                    const int b[], size_t len_b) {
    for (size_t i = 0; i < (len_a + len_b - 1);) {
        if (i < len_b) {
            result[i] = b[i];
            //i++;
        }

        if (i < len_a) {
            result[i] = a[i];
            //i++;
        }
    }
}

int main(void) {
    int a[] = {1,2,3,4};
    int b[] = {5,6,7,8};
    size_t len_a = sizeof(a) / sizeof(int);
    size_t len_b = sizeof(b) / sizeof(int);

    int result[len_a + len_b];

    merge_altering(result, a, len_a, b, len_b);

    for (size_t i = 0; i < (len_a + len_b - 1); i++) {
        printf("%d ", result[i]);
    }
    return EXIT_SUCCESS;
}