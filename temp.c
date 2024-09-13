#include <stdio.h>
#include <math.h>

int main()
{
    double a = 0, b = 0, c = 0;
    double d, x1, x2, re, im;
    int i = 0;

    scanf("%lf %lf %lf", &a, &b, &c);

    d = b * b - 4 * a * c;

    if (d < 0) {
        re = (-b) / (2 * a);
        im = sqrt(-d) / (2 * a);

        if (im < 0) {
            im *= -1;
        }

        printf("x1 = %g + %gi\nx2 = %g - %gi\n", re, im, re, im);
    }
    else if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);

        printf("x1 = %g\nx2 = %g\n", x1, x2);
    }
    else {
        x1 = x2 = (-b) / (2 * a);

        printf("x = %g\n", x1);
    }

    return 0;
}