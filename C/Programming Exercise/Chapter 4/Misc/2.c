#include <stdio.h>
#include <math.h>

int main()
{
    int grid[9][9];
    int i, j, sum, ok = 1;

    // Take input
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Check row
    for (i = 0; i < 9; i++) {
        sum = 0;

        for (j = 0; j < 9; j++) {
            sum += grid[i][j];
        }

        if (sum != 45) {
            ok = 0;
        }
    }

    // Check column
    for (i = 0; i < 9; i++) {
        sum = 0;

        for (j = 0; j < 9; j++) {
            sum += grid[j][i];
        }

        if (sum != 45) {
            ok = 0;
        }
    }

    // Check box
    for (i = 1; i <= 7; i += 3) {
        for (j = 1; j <= 7; j += 3) {
            sum = grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1];
            sum += grid[i][j - 1] + grid[i][j] + grid[i][j + 1];
            sum += grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1];
        }

        if (sum != 45) {
            ok = 0;
        }
    }

    // Check range
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if ((grid[i][j] < 1) || (grid[i][j] > 9)) {
                ok = 0;
            }
        }
    }

    if (ok) {
        printf("Correct.\n");
    }
    else {
        printf("Incorrect.\n");
    }

    return 0;
}