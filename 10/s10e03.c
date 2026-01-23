#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 80
int write_n(const char *src_path, const char *dst_path, int n) {
    if (n < 1) {
        return -1;
    }

    FILE *src = fopen(src_path, "r");
    if (src == NULL) {
        return -2;
    }

    char buffer[MAX_LINE_LENGTH + 2];
    int line_count = 0;
    int written_anything = 0;

    FILE *dst = fopen(dst_path, "w");

    while (fgets(buffer, sizeof(buffer), src) != NULL) {
        line_count++;

        if (line_count % n == 0) {
            if (dst == NULL) {
                dst = fopen(dst_path, "w");
                if (dst == NULL) {
                    fclose(src);
                    return -3;
                }
            }

            if (fprintf(dst, "%s", buffer) < 0) {
                fclose(src);
                fclose(dst);
                return -5;
            }
            written_anything = 1;
        }
    }

    if (ferror(src)) {
        fclose(src);
        if (dst != NULL) {
            fclose(dst);
        }
        return -4;
    }

    fclose(src);

    if (dst != NULL) {
        fclose(dst);
    }

    if (!written_anything) {
        return 0;
    }

    return 0;
}

int main(void) {
    return EXIT_SUCCESS;
}
