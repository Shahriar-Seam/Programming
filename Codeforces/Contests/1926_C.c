#include <stdio.h>

int sum_of_digits(int n)
{
    int sum = 0;

    while (n != 0) {
        sum += n % 10;

        n /= 10;
    }

    return sum;
}

void _sum(int *sum)
{
    int i;

    for (i = 1; i <= 200000; i++) {
        sum[i] = sum[i - 1] + sum_of_digits(i);
    }
}

int main() {
    int t, n, i;
    int sum[200001] = {};

    _sum(sum);

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        printf("%d\n", sum[n]);
    }

    return 0;
}
