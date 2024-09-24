#include <stdio.h>

int digit_sum(int n, int b)
{
    int sum = 0;

    while (n > 0) {
        sum += n % b;

        n /= b;
    }

    return sum;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int a, sum = 0, i, g;

    scanf("%d", &a);

    for (i = 2; i < a; i++) {
        sum += digit_sum(a, i);
    }

    g = gcd(sum, a - 2);

    printf("%d/%d\n", sum / g, (a - 2) / g);

    return 0;
}