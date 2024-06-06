#include <stdio.h>

double sum_of_digits(int n);

int main()
{
    int n;
    double sum;

    printf("Enter a number: ");
    scanf("%d", &n);

    sum = sum_of_digits(n);

    printf("Sum of the digits of %d is: %.0lf\n", n, sum);

    return 0;
}

double sum_of_digits(int n)
{
    int n0 = n, len = 0, d, i;
    double sum = 0;

    while (d != 0) {
        d = n0 / 10;
        n0 = d;
        len++;
    }

    for (i = 0; i < len; i++) {
        sum += n % 10;
        n = n / 10;
    }

    return sum;
}