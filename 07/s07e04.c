#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char values[] = "0123456789";       //Declaring an character array 'values'
    char *p1 = values;                  //the pointer p1 points at the first element of values
    char *p2 = values + strlen(values); //the pointer p2 points at the eleventh element of values (does not exist, since the array only carries ten values)
    printf("1. %c\n", *(p1 + 4));       //prints the character located at values[4]      
    printf("2. %c\n", *p2);             //prints the character located at values[10] -> does not exist, so it prints nothing
    printf("3. %d\n", p1 < p2);         //the memory address of p1 is located at a lower point than the address of p2 (further down the line), therefore this is true resulting in 1
    printf("4. %d\n", (p1 + 2) < (p2 - 4));
    printf("5. %d\n", (((int32_t *)p1) + 2) < (int32_t *)(p2 - 4));
    printf("6. %td\n", p2 - p1);        //
    return EXIT_SUCCESS;
}

