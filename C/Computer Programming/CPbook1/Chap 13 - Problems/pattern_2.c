#include <stdio.h>

int main()
{
    int i, j, k, n;

    scanf("%d", &n);

    for (i = 0; i < n - 1; i++) {
        for (j = i; j > 0; j--) {
            printf(" ");
        }

        for (k = 2 * (n - i) - 1; k > 0; k--) {
            printf("C");
        }

        if (i == n - 2) {
            break;
        }

        printf("\n");
    }

    for (i = 0; i <= n; i++) {
        for (j = i - 1; j < n - 1; j++) {
            printf(" ");
        }

        for (k = 0; k < 2 * i - 1; k++) {
            printf("C");
        }

        printf("\n");
    }

    return 0;
}