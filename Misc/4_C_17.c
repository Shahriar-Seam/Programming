#include <stdio.h>

int main()
{
    int n, i, j;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (j = 0; j <= i; j++) {
                printf("%d ", (j + 1) & 1);
            }
        }
        else {
            for (j = 1; j <= i + 1; j++) {
                printf("%d ", (j + 1) & 1);
            }
        }

        printf("\n");
    }

    return 0;
}