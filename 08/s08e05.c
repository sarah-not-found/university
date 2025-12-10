#include <stdio.h>
#include <stdlib.h>

#define START_SYMBOL 'S'
#define END_SYMBOL 'E'
#define PATH_SYMBOL 'O'
#define FREE_SYMBOL ' '
#define ROWS 21
#define COLS 42

typedef struct point {
    int row;
    int col;
} point_t;

void print_grid(char grid[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS - 1; c++) {
            printf("%c ", grid[r][c]);
        }
        putchar('\n');
    }
}

int is_valid(const point_t point, char grid[ROWS][COLS]) {
    //Checks if a point is valid according to our rules
    if (point.row < 0 || point.row >= ROWS || point.col < 0 || point.col >= COLS) {
        return 0;
    }

    if (grid[point.row][point.col] != FREE_SYMBOL &&
        grid[point.row][point.col] != START_SYMBOL &&
        grid[point.row][point.col] != END_SYMBOL) {
        return 0;
    }
    return 1;
}

int find_path_recursive(point_t end, point_t next, char grid[ROWS][COLS]) {
    if (next.row == end.row && next.col == end.col) {
        return 1; // reached the end
    }

    const int moves[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

    for (int i = 0; i < 4; i++) {
        point_t next_step = {next.row + moves[i][0], next.col + moves[i][1]};

        if (is_valid(next_step, grid)) {
            // Mark as visited temporarily
            if (grid[next_step.row][next_step.col] != START_SYMBOL &&
                grid[next_step.row][next_step.col] != END_SYMBOL) {
                grid[next_step.row][next_step.col] = PATH_SYMBOL;
                }

            if (find_path_recursive(end, next_step, grid)) {
                return 1; // path confirmed
            }

            // Backtrack: unmark
            if (grid[next_step.row][next_step.col] == PATH_SYMBOL) {
                grid[next_step.row][next_step.col] = FREE_SYMBOL;
            }
        }
    }

    return 0; // no path found
}

int find_path(char grid[ROWS][COLS]) {
    point_t start = {.row = ROWS + 1, .col = COLS + 1};
    point_t end = {.row = ROWS + 1, .col = COLS + 1};

    // Find start
    int found_start = 0;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS - 1; c++) {
            if (grid[r][c] == START_SYMBOL) {
                start.row = r;
                start.col = c;
                found_start = 1;
                break;
            }
        }
    }

    if (!found_start) {
        printf("No start point 'S' found");
        return 0;
    }

    // Find end
    int found_end = 0;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS - 1; c++) {
            if (grid[r][c] == END_SYMBOL) {
                end.row = r;
                end.col = c;
                found_end = 1;
                break;
            }
        }
    }

    if (!found_end) {
        printf("No end point 'E' found");
        return 0;
    }

    return find_path_recursive(end, start, grid);
}

int main(void) {
    char grid[ROWS][COLS] = {
        "+-------------+-+---+-------------+-----+",
        "|             | |S  |             |     |",
        "| +-----+---+ | + + | +-----+ +-+ +-+ +-+",
        "|       |   | |   | | |     | | |   |   |",
        "| +---+ | + | | +-+ + + +---+ | +-+ +-+ |",
        "| |   | | | | |   |     |     |   |     |",
        "+-+ + | | | | +---+-----+ +---+-+ +-+-+ |",
        "|   | | | | |     |       |       | |   |",
        "| +-+ + | | +---+ + +-----+-+ +-+ + | +-+",
        "|   |   | | |   |   |         | |   |   |",
        "+-+ +---+ +-+ + +-+-+ + +-+---+ +-+ +-+ |",
        "| | | |       |   |   |   |         |   |",
        "| + | | +-----+ + | +-+-+ | +---+---+ +-+",
        "|   | | |     | | | |     |     |   |   |",
        "+-+-+ | +---+ | | +-+ +---+---+ | + +-+ |",
        "| |   |       | |     |         | |   | |",
        "| + + +-----+ | | +---+-------+-+ | + | |",
        "|   |       | | | |           |   | | | |",
        "| +-+ +-----+ | +-+ +-------+ + +-+ +-+ |",
        "|   |         |     E       |     |     |",
        "+---+---------+-------------+-----+-----+",
    };
    print_grid(grid);
    printf("\nsolution found: %s\n", find_path(grid) ? "yes" : "no");
    print_grid(grid);
    return EXIT_SUCCESS;
}
