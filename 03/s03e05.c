/* TODO: include other headers if needed */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void) {
    /* TODO: Implement logic */
    //Declaring variables
    uint32_t value = 0;
    int zero_counter = 0;
    
    //Enter values:
    printf("value: ");
    scanf("%" SCNu32, &value);
    printf("\n");

    //Printing out the number, before it's altered (saving a variable)
    printf("The number ");
    printf("%" PRIu32, value);
    
    //Execption case zero:
    if (value == 0) {
        zero_counter++;
    }

    //Logic:
    while (value > 0) {
        if ((value % 2) == 0) {
            zero_counter++;
        }  
        value = value / 2;
    }

    //Printing out the result:
    if (zero_counter != 1) {
        printf(" contains %d zeros in the significant digits of the binary representation!", zero_counter);
    } else {
        printf(" contains 1 zero in the significant digits of the binary representation!");
    }
    printf("\n");
    return EXIT_SUCCESS;
}
