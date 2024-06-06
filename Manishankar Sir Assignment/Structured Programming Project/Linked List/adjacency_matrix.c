#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i, j, n, weight;

    printf("Enter number of vertices: \n");
    scanf("%d", &n);

    int matrix[n][n] = {};

    while (true) {
        scanf("%d %d %d", &i, &j, &weight);

        if (i == 0 && j == 0 && weight == 0) {
            break;
        }

        i--;
        j--;

        if (i < 0 || j < 0 || weight <= 0 || i >= n || j >= n) {
            puts("Invalid input");
            continue;
        }

        matrix[i][j] = matrix[j][i] = weight;
    }

    printf("    ");
    for (i = 0; i < n; i++) {
        printf("%d ", i + 1);
    }
    puts("");

    printf("----");
    for (i = 0; i < n; i++) {
        printf("--");
    }
    puts("");

    for (i = 0; i < n; i++) {
        printf("%d | ", i + 1);

        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }

        puts("");
    }

    return 0;
}