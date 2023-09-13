#include <stdio.h>

int main()
{
    int pascal[20][20], n;

    for (int i = 0; i < 20; i++) {
        pascal[i][0] = pascal[i][i] = 1;
        for (int j = 1; j < i; j++) {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("%d", pascal[n - 1][i]);

        if (i == n - 1) {
            printf("\n");
        }
        else {
            printf(" ");
        }
    }

    return 0;
}