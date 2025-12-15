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

int is_valid(const int row, const int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }
    return 1;
}
int is_free(const int row, const int col, char grid[ROWS][COLS]) {
    return grid[row][col] == FREE_SYMBOL || grid[row][col] == END_SYMBOL;
}

int find_path_recursive(point_t next, const point_t end, char grid[ROWS][COLS]) {

    if (next.row == end.row && next.col == end.col) {
        return 1;
    }

    if (grid[next.row][next.col] != START_SYMBOL) {
        grid[next.row][next.col] = '#';
    }

    point_t dirs[4] = {
        {next.row+1, next.col},
        {next.row, next.col+1},
        {next.row-1, next.col},
        {next.row, next.col-1}
    };

    for (int i = 0; i < 4; i++) {
        point_t dir = dirs[i];
        if (is_valid(dir.row, dir.col) && is_free(dir.row, dir.col, grid)) {
            if (find_path_recursive(dir, end, grid)) {
                if (grid[dir.row][dir.col] != START_SYMBOL &&
                    grid[dir.row][dir.col] != END_SYMBOL) {
                    grid[dir.row][dir.col] = PATH_SYMBOL;
                }
                return 1;
            }
        }
    }
    if (grid[next.row][next.col] != START_SYMBOL) {
        grid[next.row][next.col] = FREE_SYMBOL;
    }
    return 0;
}

int find_path(char grid[ROWS][COLS]) {
    point_t start = {5,5};
    //Find the start-point
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (grid[r][c] == START_SYMBOL) {
                start.row = r;
                start.col = c;
            }
        }
    }

    point_t end = {7,7};
    //Find end-point
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (grid[r][c] == END_SYMBOL) {
                end.row = r;
                end.col = c;
            }
        }
    }

    return find_path_recursive(start, end, grid);
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
