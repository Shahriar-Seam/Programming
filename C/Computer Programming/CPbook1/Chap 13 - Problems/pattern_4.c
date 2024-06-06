#include <stdio.h>

int main()
{
    int i, j, k, m, n = 10;

    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            printf("C");
        }

        for (k = 0; k < 2 * (n - i) - 2; k++) {
            printf(" ");
        }

        for (m = 0; m <= i; m++) {
            printf("C");
        }

        printf("\n");
    }

    return 0;
}