#define MAX_LEN_NAME 64
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lecture_hall {
    char name[MAX_LEN_NAME + 1];
    unsigned short size;
    unsigned short num_seats;
} lecture_hall_t;

void print_lecture_hall(const lecture_hall_t *lecture_hall) {
    printf("%s ", lecture_hall->name);
    printf("%hu ", lecture_hall->size);
    printf("%hu\n", lecture_hall->num_seats);
}

int cmp_lexicographic(const void *a, const void *b) {
    const char *const *str_a = a;
    const char *const *str_b = b;
    return strcmp(*str_a, *str_b);
}

int cmp_numeric(const void *a, const void *b) {
    const unsigned short *const *num_a = a;
    const unsigned short *const *num_b = b;
    return *num_b - *num_a;
}

const char *name_comparator(const char *a, const char *b) {
    const char *names[2] = {a, b};
    qsort(names, 2, sizeof(char *), cmp_lexicographic);
    //printf("%s %s\n", names[0], names[1]);
    return names[0];
}

unsigned short size_comparator(const unsigned short *a, const unsigned short *b) {
    unsigned short sizes[2] = {*a, *b};
    qsort(sizes, 2, sizeof(unsigned short), cmp_numeric);
    //printf("%hu %hu\n", sizes[0], sizes[1]);
    return sizes[0];
}

unsigned short num_seats_comparator(const unsigned short *a, const unsigned short *b) {
    unsigned short seats[2] = {*a, *b};
    qsort(seats, 2, sizeof(unsigned short), cmp_numeric);
    //printf("%hu %hu\n", seats[0], seats[1]);
    return seats[0];
}

void lecture_hall_comparator(struct lecture_hall *my_lecture_hall, struct lecture_hall *my_lecture_hall2) {
    if (my_lecture_hall->num_seats == my_lecture_hall2->num_seats) {
        size_comparator(&my_lecture_hall->size, &my_lecture_hall2->size);
    } else {
        num_seats_comparator(&my_lecture_hall->num_seats, &my_lecture_hall2->num_seats);
    }
}

void sort_lecture_halls(lecture_hall_t *lecture_halls,
                        size_t num_lecture_halls,
                        int (*comparator)(const void *, const void *)) {
    qsort(lecture_halls, num_lecture_halls, sizeof(lecture_hall_t), comparator);
}

int name_qsort_adapter(const void *a, const void *b) {
    const lecture_hall_t *lecture_hall1 = a;
    const lecture_hall_t *lecture_hall2 = b;

    const char *first = name_comparator(lecture_hall1->name, lecture_hall2->name);

    if (first == lecture_hall1->name) return -1;
    if (first == lecture_hall2->name) return 1;
    return 0;
}

int size_qsort_adapter(const void *a, const void *b) {
    const lecture_hall_t *lecture_hall1 = a;
    const lecture_hall_t *lecture_hall2 = b;

    unsigned short first = size_comparator(&lecture_hall1->size, &lecture_hall2->size);

    if (first == lecture_hall1->size) return -1;
    if (first == lecture_hall2->size) return 1;
    return 0;
}

int num_seats_qsort_adapter(const void *a, const void *b) {
    const lecture_hall_t *lecture_hall1 = a;
    const lecture_hall_t *lecture_hall2 = b;

    unsigned short first = num_seats_comparator(&lecture_hall1->num_seats, &lecture_hall2->num_seats);

    if (first == lecture_hall1->num_seats) return -1;
    if (first == lecture_hall2->num_seats) return 1;
    return 0;
}

int main(void) {
    lecture_hall_t my_lecture_hall = {
        .name = "Sarah's lecture hall",
        .size = 330,
        .num_seats = 404
    };

    lecture_hall_t my_lecture_hall2 = {
        .name = "Leo's lecture hall",
        .size = 500,
        .num_seats = 800
    };

    lecture_hall_t my_lecture_hall3 = {
        .name = "Lea's lecture hall",
        .size = 200,
        .num_seats = 120
    };

    lecture_hall_t my_lecture_hall4 = {
        .name = "Origami's lecture hall",
        .size = 320,
        .num_seats = 240
    };

    print_lecture_hall(&my_lecture_hall);
    name_comparator(my_lecture_hall.name, my_lecture_hall2.name);
    size_comparator(&my_lecture_hall.size, &my_lecture_hall2.size);
    num_seats_comparator(&my_lecture_hall.num_seats, &my_lecture_hall2.num_seats);

    lecture_hall_comparator(&my_lecture_hall, &my_lecture_hall2);

    lecture_hall_t lecture_hall_array[] = {
        my_lecture_hall,
        my_lecture_hall2,
        my_lecture_hall3,
        my_lecture_hall4
    };

    printf("\n\n");
    sort_lecture_halls(lecture_hall_array, 4, name_qsort_adapter);

    for (size_t i = 0; i < 4; i++) {
        print_lecture_hall(&lecture_hall_array[i]);
    }
    return EXIT_SUCCESS;
}
