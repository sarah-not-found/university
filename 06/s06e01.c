#include <stdlib.h>
#include <stdio.h>

void reverse(int values[], size_t length) {
    for (size_t i = 0; i < (length / 2); i++) {
        int frontValue = values[i];
        values[i] = values[length - i - 1];  
        values[length - i - 1] = frontValue; 
    }
}

int main(void) {
    int values[] = {1, 2, 3, 4, 5};

    reverse(values, sizeof(values)/sizeof(int));
    
    for (size_t i = 0; i < sizeof(values)/sizeof(int); i++) {
        printf("%d ", values[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
