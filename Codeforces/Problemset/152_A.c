#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, m, i, j, max_marks, count = 0;

    scanf("%d %d", &n, &m);

    char nums[n][m + 1];
    int *counter = (int *) calloc(n, sizeof(int));

    for (i = 0; i < n; i++) {
        scanf(" %s", nums[i]);
    }

    for (i = 0; i < m; i++) {
        max_marks = 0;

        for (j = 0; j < n; j++) {
            max_marks = max(max_marks, nums[j][i] - '0');
        }

        for (j = 0; j < n; j++) {
            counter[j] += (max_marks == nums[j][i] - '0');
        }
    }

    for (i = 0; i < n; i++) {
        count += (counter[i] > 0);
    }

    printf("%d\n", count);

    return 0;
}