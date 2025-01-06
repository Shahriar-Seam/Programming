#include <stdio.h>

int tiles;

void count(int h, int w, char s[h][w + 1], int x, int y, int visited[20][20])
{
    if (x < 0 || y < 0 || x >= w || y >= h) {
        return;
    }
    else if (s[y][x] == '#') {
        return;
    }
    else if (!visited[x][y]) {
        visited[x][y] = 1;
        tiles++;

        count(h, w, s, x + 1, y, visited);
        count(h, w, s, x - 1, y, visited);
        count(h, w, s, x, y + 1, visited);
        count(h, w, s, x, y - 1, visited);
    }
}

int main()
{
    while (1) {
        int w, h, i, j, x, y;
        int visited[20][20] = {};
        tiles = 0;

        scanf("%d %d", &w, &h);

        if (w == 0 && h == 0) {
            break;
        }

        char s[h][w + 1];

        for (i = 0; i < h; i++) {
            scanf(" %s", s[i]);
        }

        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                if (s[i][j] == '@') {
                    x = j;
                    y = i;
                }
            }
        }

        count(h, w, s, x, y, visited);

        printf("%d\n", tiles);
    }

    return 0;
}