#include <stdio.h>

double power(double b, double p) // b = base, p = power
{
    double result = 1;

    while (p--)
    {
        result *= b;
    }

    return result;
}

double factorial(double n)
{
    double fact = 1;
    int i;

    for (i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
}

int main()
{
    int i;
    double y = 0, x;

    scanf("%lf", &x);

    for (i = 0; i < 10; i++) {
        y += power(-1, i) * power(x, 2 * i + 1) / factorial(2 * i + 1);
    }

    printf("sin(%lf) = %lf\n", x, y);

    return 0;
}