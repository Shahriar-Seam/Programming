#include <stdio.h>

int main()
{
    int n, i, j, k;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = i; j > 1; j--) {
            printf(" ");
        }
        for (k = n; k >= i; k--) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}