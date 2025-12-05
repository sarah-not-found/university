#include <stdio.h>
#include <stdlib.h>

unsigned f2(unsigned a); //unsigned f2(unsigned); works too, because the compiler doesn't need to know the name of the variable
/*
The program won't compile without the previous declaration, because we need to tell
the program that there will be a funciton f2 later on in the program.
Without the declaration, the program runs into an error, because it does not know what to do with
'f2' and therefore doesn't run
*/

unsigned f1(unsigned a, unsigned b) {
    if (a < b) {
        return a + b;
    }
    return f2(a - b);
}

unsigned f2(unsigned a) { 
    return f1(a >> 1, 5); 
}

int main(void) {
    printf("%u\t%u\n", f1(1, 2), f2(3));
    printf("%u\t%u\n", f1(4, 5), f2(6));
    return EXIT_SUCCESS;
}
