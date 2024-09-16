#include <stdio.h>

int main()
{
    int n, i, j, k, sum = 1;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        if (i > 1) {
            printf("%d ", sum);
        }

        for (j = 1; j <= i; j++) {
            sum = 1;
            
            for (k = 1; k <= j; k++) {
                sum = sum * (i - j + k) / k;
            }

            printf("%d ", sum);
        }

        printf("\n");
    }

    return 0;
}