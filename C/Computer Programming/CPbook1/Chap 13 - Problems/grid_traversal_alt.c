#include <stdio.h>

int main()
{
    int grid[10][10];
    int i, j, n, x = 0, y = 0, x1, y1;
    char c;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            grid[i][j] = 1;
        }
    }

    printf("Enter the number of blocked cells: \n");
    scanf("%d", &n);
    if (n != 0) {
        printf("Now enter the cells: \n");
    }

    for (i = 0; i < n; i++) {
        scanf("%d %d", &x1, &y1);
        grid[x1][y1] = 0;
    }

    printf("Enter initial position: \n");
    scanf("%d %d", &x, &y);

    if (grid[x][y] == 0) {
        printf("Blocked cell.\n");
    }

    else {
        while (1) {
            scanf("%c", &c);

            if (c == 'S') {
                break;
            }
            if (c == 'U') {
                x--;
                if (grid[x][y] == 0) {
                    printf("Blocked cell.\n");
                    x++;
                }
                if (x < 0) {
                    printf("Out of grid.\n");
                    x++;
                    break;
                }
            }
            if (c == 'D') {
                x++;
                if (grid[x][y] == 0) {
                    printf("Blocked cell.\n");
                    x--;
                }
                if (x > 9) {
                    printf("Out of grid.\n");
                    x--;
                    break;
                }
            }
            if (c == 'L') {
                y--;
                if (grid[x][y] == 0) {
                    printf("Blocked cell.\n");
                    y++;
                }
                if (y < 0) {
                    printf("Out of grid.\n");
                    y++;
                    break;
                }
            }
            if (c == 'R') {
                y++;
                if (grid[x][y] == 0) {
                    printf("Blocked cell.\n");
                    y--;
                }
                if (y > 9) {
                    printf("Out of grid.\n");
                    y--;
                    break;
                }
            }
        }
    }

    printf("Final position: %d %d\n", x, y);

    return 0;
}