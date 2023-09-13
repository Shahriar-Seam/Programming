#include <stdio.h>

int main()
{
    int n, i, j, k, m;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 1; j <= n - i - 1; j++) {
            printf(" ");
        }
        printf("*");
        for (j = 1; j <= 2 * i - 1; j++) {
            printf(" ");
        }
        if (i > 0) {
            printf("*");
        }
        printf("\n");
    }

    for (i = n - 2; i >= 0; i--) {
        for (j = i; j <= n - 2; j++) {
            printf(" ");
        }
        printf("*");
        for (j = 0; j < 2 * i - 1; j++) {
            printf(" ");
        }
        if (i > 0) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

// https://chat.openai.com/share/6d4f07a7-1659-4057-97dd-3af5ddfb223c