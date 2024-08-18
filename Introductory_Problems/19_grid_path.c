#include <stdio.h>
#include <string.h>

#define GRID_SIZE 7
#define PATH_LENGTH 48

// Function to count the number of paths
int count_paths(char *path, int x, int y, int step, int memo[GRID_SIZE][GRID_SIZE][PATH_LENGTH]) {
    if (x == GRID_SIZE - 1 && y == 0) {
        return step == PATH_LENGTH ? 1 : 0;
    }

    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE || step >= PATH_LENGTH) {
        return 0;
    }

    if (memo[x][y][step] != -1) {
        return memo[x][y][step];
    }

    int result = 0;

    if (path[step] != '?') {
        if (path[step] == 'R') result = count_paths(path, x + 1, y, step + 1, memo);
        if (path[step] == 'L') result = count_paths(path, x - 1, y, step + 1, memo);
        if (path[step] == 'U') result = count_paths(path, x, y - 1, step + 1, memo);
        if (path[step] == 'D') result = count_paths(path, x, y + 1, step + 1, memo);
    } else {
        result = count_paths(path, x + 1, y, step + 1, memo) +
                 count_paths(path, x - 1, y, step + 1, memo) +
                 count_paths(path, x, y - 1, step + 1, memo) +
                 count_paths(path, x, y + 1, step + 1, memo);
    }

    memo[x][y][step] = result;
    return result;
}

int main() {
    char path[PATH_LENGTH + 1];
    int memo[GRID_SIZE][GRID_SIZE][PATH_LENGTH];
    int i, j, k;

    // Initialize memo array with -1
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            for (k = 0; k < PATH_LENGTH; k++) {
                memo[i][j][k] = -1;
            }
        }
    }

    // Input path string
    strcpy(path, "??????R??????U??????????????????????????LD?????D");

    // Output the number of valid paths
    printf("%d\n", count_paths(path, 0, 0, 0, memo));

    return 0;
}
