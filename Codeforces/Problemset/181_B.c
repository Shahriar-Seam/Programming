#include <stdio.h>
#include <stdlib.h>

int is_valid(int **xy, int x1, int x2, int y1, int y2)
{
    if (((x1 + x2) % 2 == 0) && ((y1 + y2) % 2 == 0)) {
        return xy[((x1 + x2) / 2) + 1000][((y1 + y2) / 2) + 1000];
    }
    else {
        return 0;
    }
}

int main()
{
    int n, i, j, count = 0;

    scanf("%d", &n);

    int x[n], y[n], **xy;

    xy = (int **) malloc(sizeof(int *) * 2005);

    for (i = 0; i < 2005; i++) {
        xy[i] = (int *) calloc(2005, sizeof(int));
    }

    for (i = 0; i < n; i++) {
        scanf("%d %d", x + i, y + i);

        xy[x[i] + 1000][y[i] + 1000]++;
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            count += is_valid(xy, x[i], x[j], y[i], y[j]);
        }
    }

    printf("%d\n", count);

    return 0;
}