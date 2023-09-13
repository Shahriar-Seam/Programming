#include <stdio.h>

int main()
{
    int i, j, k, n;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 0; j < i; j++) {
            printf("C");
        }

        for (k = 2 * (n - i); k > 0; k--) {
            printf(" ");
        }

        for (j = 0; j < i; j++) {
            printf("C");
        }

        printf("\n");
    }

    return 0;
}