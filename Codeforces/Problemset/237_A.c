#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, h, m, i, j, k = 0;
    int counter[24][60] = {};

    scanf("%d", &n);

    while (n--) {
        scanf("%d %d", &h, &m);

        counter[h][m]++;
    }

    for (i = 0; i < 24; i++) {
        for (j = 0; j < 60; j++) {
            k = max(k, counter[i][j]);
        }
    }

    printf("%d\n", k);

    return 0;
}