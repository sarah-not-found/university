#include <stdlib.h>

int a; //Global Variable

int main(void) {
    a = 1;
    {
        a = 2;
        char a;
        a = 3;
        {
            int a;
            a = 4;
        }
        {
            a = 5;
        }
        a = 6;
    }
    a = 7;
    return EXIT_SUCCESS;
}
