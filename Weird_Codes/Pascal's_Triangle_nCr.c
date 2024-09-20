#include <stdio.h>

int main()
{
    int n, i, j, k, sum = 1;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 0; j < n - i; j++) {
            printf(" ");
        }

        if (i > 1) {
            printf("%d ", sum);
        }
        else {
            printf(" ");
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
