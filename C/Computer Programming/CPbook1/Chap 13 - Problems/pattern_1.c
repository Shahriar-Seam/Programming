#include <stdio.h>

int main()
{
    int i, j, n;

    scanf("%d", &n);

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i; j++) {
            printf("C");
        }

        if (i == n - 2) {
            break;
        }

        printf("\n");
    }

    for (i = 0; i <= n; i++) {
        for (j = i; j > 0; j--) {
            printf("C");
        }

        printf("\n");
    }

    return 0;
}