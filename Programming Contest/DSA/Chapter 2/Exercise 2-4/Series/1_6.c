#include <stdio.h>

int main()
{
    int n, i, j, k, l = 1, num, sum = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            num = 1;

            for (k = 1; k <= j; k++) {
                num *= l++;
            }

            sum += num;
        }
    }

    printf("%d\n", sum);

    return 0;
}