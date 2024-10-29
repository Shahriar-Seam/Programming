#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n, i, j, min_time = (int) 1e9, time;

    scanf("%d", &n);

    int v[n];

    for (i = 0; i < n; i++) {
        scanf("%d", v + i);
    }

    int **arr = (int **) malloc(sizeof(int *) * n);

    for (i = 0; i < n; i++) {
        arr[i] = (int *) malloc(sizeof(int) * v[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < v[i]; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        time = 0;
        for (j = 0; j < v[i]; j++) {
            time += 5 * arr[i][j];
        }

        time += 15 * v[i];

        min_time = min(min_time, time);
    }

    printf("%d\n", min_time);

    return 0;
}