#include <stdlib.h>
//#include <stdio.h>

unsigned square_pyramidal_number(unsigned height) {
    if (height > 0) {
        return (height * height) + square_pyramidal_number(height - 1); 
    } else {
        return 0;
    }
}

int main(void) {
/*
    unsigned height = 0;
    scanf("%u", &height);
    printf("%u\n", square_pyramidal_number(height));
*/
    unsigned height = 0;
    square_pyramidal_number(height);
    return EXIT_SUCCESS;
}
