#include <stdio.h>
#include <math.h>

int main()
{
    int t, n, sum1, sum2, sum, i;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        sum1 = 2 << n - 1;
        sum2 = 0;

        for (i = 1; i < n / 2; i++) {
            sum1 += 1 << i;
        }
        for (i = n / 2; i < n; i++) {
            sum2 += 1 << i;
        }

        sum = sum1 - sum2;

        printf("%d\n", sum);
    }

    return 0;
}