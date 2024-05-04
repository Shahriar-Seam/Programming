#include <stdio.h>

int div_sum(int n)
{
    int i, sum = 1;

    for (i = n / 2; i > 1; i--) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum;
}

int main()
{
    int i, n, m, sum = 0;

    for (i = 0; i <= 10000; i++) {
        n = div_sum(i);
        m = div_sum(n);

        if (m == i && m != n) {
            printf("%d %d\n", m, n);

            sum += m + n;
        }
    }

    printf("Sum = %d\n", sum / 2);

    return 0;
}