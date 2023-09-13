#include <stdio.h>

int main()
{
    int i, j, k, n;

    scanf("%d", &n);

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }

        for (k = 0; k < n - i; k++) {
            printf("C");
        }

        printf("\n");
    }

    for (i = n - 1; i >= 0; i--) {
        for (j = i; j > 0; j--) {
            printf(" ");
        }

        for (k = 0; k < n - i; k++) {
            printf("C");
        }

        printf("\n");
    }

    return 0;
}