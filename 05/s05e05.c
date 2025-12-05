#include <stdlib.h>
#include <stdio.h>

unsigned fibonacci_recursive(unsigned n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

unsigned fibonacci_iterative(unsigned n) {
    unsigned f0 = 0; unsigned f1 = 1;
    for (unsigned i = n/2; i > 0; --i) {
        f0 = f0 + f1; //basically f of all even numbers (f2, f4, f6...)
        f1 = f0 + f1; //basically f of all odd numbers  (f3, f5, f7...)
    }
    return (n % 2) == 1 ? f1 : f0;
}

int main(void) {
    unsigned n = 0;
    fibonacci_recursive(n);
    fibonacci_iterative(n);
    return EXIT_SUCCESS;
}
