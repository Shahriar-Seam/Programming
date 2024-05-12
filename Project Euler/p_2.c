#include <stdio.h>
#include <math.h>

double bin_exp(double b, int p)
{
    double result = 1;

    while (p > 0) {
        if (p & 1) {
            result = result * b;
        }

        b = b * b;

        p >>= 1;
    }

    return result;
}

int fibonacci(int n)
{
    int i;
    double phi, phi_c;

    phi = (1 + sqrt(5)) / 2;
    phi_c = (1 - sqrt(5)) / 2;

    return round((1 / sqrt(5)) * (bin_exp(phi, n) - bin_exp(phi_c, n)));
}

int main()
{
    int i, sum = 0;

    sum = fibonacci(45);

    printf("%d\n", sum);

    return 0;
}