// I don't know how to play Minesweeper.
// I don't understand the code, how it works, why it works, whatever it does.

#include <stdio.h>

int main()
{
    int grid[12][12] = {0}, m_count = 0, m_location[20][2] = {0};
    int i, j, x, y;

    scanf("%d", &m_count);
    for (i = 0; i < m_count; i++) {
        scanf("%d %d", &m_location[i][0], &m_location[i][1]);
    }

    for (i = 0; i < m_count; i++) {
        x = m_location[i][0];
        y = m_location[i][1];

        grid[x - 1][y - 1] += 1;
        grid[x - 1][y] += 1;
        grid[x - 1][y + 1] += 1;

        grid[x][y - 1] += 1;
        grid[x][y + 1] += 1;

        grid[x + 1][y - 1] += 1;
        grid[x + 1][y] += 1;
        grid[x + 1][y + 1] += 1;
    }

    for (i = 0; i < m_count; i++) {
        x = m_location[i][0];
        y = m_location[i][1];

        grid[x][y] = 100;
    }

    for (i = 1; i < 11; i++) {
        for (j = 1; j < 11; j++) {
            if (grid[i][j] == 100) {
                printf("*");
            }
            else {
                printf("%d", grid[i][j]);
            }
        }

        printf("\n");
    }

    return 0;
}