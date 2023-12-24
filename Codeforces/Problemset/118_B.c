#include <stdio.h>

void pattern(int n)
{
    int i, j, k;

    for (i = 0; i < n; i++) {
        for (k = n; k > i; k--) {
            printf("  ");
        }

        for (j = 0; j <= i; j++) {
            printf("%d", j);

            if (i != 0) {
                printf(" ");
            }
        }
        
        for (j = i - 1; j >= 0; j--) {
            printf("%d", j);

            if (j != 0) {
                printf(" ");
            }
        }

        printf("\n");
    }

    for (i = n; i >= 0; i--) {
        for (k = n; k > i; k--) {
            printf("  ");
        }

        for (j = 0; j <= i; j++) {
            printf("%d", j);

            if (i != 0) {
                printf(" ");
            }
        }

        for (j = i - 1; j >= 0; j--) {
            printf("%d", j);

            if (j != 0) {
                printf(" ");
            }
        }

        printf("\n");
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    pattern(n);

    return 0;
}