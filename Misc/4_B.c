#include <stdio.h>

int factorial(int n)
{
    int fact = 1, i;

    for (i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
}

int power(int n, int p)
{
    int i, num = 1;

    for (i = 0; i < p; i++) {
        num *= n;
    }

    return num;
}

int main()
{
    int n, i;
    double x, sum = 0;

    scanf("%d %lf", &n, &x);

    for (i = 0; i <= n; i += 2) {
        if (i % 4 == 0) {
            sum += (double) power(x, i) / factorial(i);
        }
        else {
            sum -= (double) power(x, i) / factorial(i);
        }
    }

    printf("%g\n", sum);

    return 0;
}