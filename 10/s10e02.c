#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        return EXIT_FAILURE;
    }

    long value;
    long min = 0;
    long max = 0;
    size_t count = 0;

    while (fscanf(file, "%ld", &value) == 1) {
        if (count == 0) {
            //first value initializes min and max
            min = value;
            max = value;
        } else {
            if (value < min) {
                min = value;
            }
            if (value > max) {
                max = value;
            }
        }
        count++;
    }

    fclose(file);

    printf("count = %zu\n", count);
    printf("min = %ld\n", min);
    printf("max = %ld\n", max);

    return EXIT_SUCCESS;
}
