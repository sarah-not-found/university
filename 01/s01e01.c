#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int value = 1;
    
    switch(value) {
        case 1:
            printf("positive one\n");
            break; //Without it it would jump into every other case below it
        case -1:
        printf("negative one\n");
            break;
        default:
            printf("other\n");
    }

    printf("%d \n", 'Z'-'A');
    printf("%d \n", (5U << 1U) == (13 ^ 7));
    printf("%d \n", (UINT_MAX + 2U) + 1);
    printf("%d \n", 0.1 - 0.1f == 0);
    return EXIT_SUCCESS;
}
