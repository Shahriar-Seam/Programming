#include <stdio.h>

int main()
{
    int i, j, k, n = 7;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }

        for (k = 0; k < n - i; k++) {
            printf("C");
        }

        if (i == n - 1) {
            break;
        }

        printf("\n");
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        for (k = 0; k <= i; k++) {
            printf("C");
        }

        printf("\n");
    }

    return 0;
}