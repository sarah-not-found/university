#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //Preparation
    int n = 0;
    scanf("%d", &n);
    printf("\n");

    //Check if n is valid
    if (n <= 0) {
        printf("ERROR: The provided number %d is smaller than 1!\n", n);
        return EXIT_FAILURE;
    }

    //Logic
        //xi+2​=xi​+1
    int x0 = 2;
    int x1 = 4;

    //Checking for the first or seccond number:
    if (n == 1) {
        printf("%d\n", x0);
        return EXIT_SUCCESS;
    }

    if (n == 2) {
        printf("%d, %d\n", x0, x1);
        return EXIT_SUCCESS;
    }
    
    if (n > 2) {
        printf("%d, %d, ", x0, x1);
        n -= 2;
        int counter = 2;
        while (n > 0) {
            //Printing every number, but  the first two (can't think of another solution)
            if ((counter % 2) != 0) {
                //x(1 + 2) = x3
                x1 += 1;
                printf("%d", x1);
            } else {
                //x(0 + 2) = x2
                x0 += 1;
                printf("%d", x0);   
            }

            //Formatting with commas
            if (n > 1) {
                printf(", ");
            }
            counter++;
            n--;
        }
    }
    printf("\n");
    return EXIT_SUCCESS;
}
