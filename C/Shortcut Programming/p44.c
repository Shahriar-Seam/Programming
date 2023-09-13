#include <stdio.h>

int main()
{
    float a, b, c, xmin, xmax, delx, x[101], y[101];
    int i;

    printf("Enter a b c xmin xmax: ");
    scanf("%f %f %f %f %f", &a, &b, &c, &xmin, &xmax);

    delx = (xmax - xmin) / 100;

    for (i = 0; i <= 100; i++) {
        x[i] = xmin + delx * i;
        y[i] = a * x[i] * x[i] + b * x[i] + c;
    }

    for (i = 1; i <= 50; i++) {
        printf("%7.4f %7.4f\t%7.4f %7.4f\n", x[i], y[i], x[50 + i], y[50 + i]);
    }

    return 0;
}