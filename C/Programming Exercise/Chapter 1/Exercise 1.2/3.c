#include <stdio.h>

int main()
{
    double n;

    scanf("%lf", &n);

    printf("%.2lf cm = %.2lf inch\n%.2lf inch = %.2lf cm\n", n, n / 2.54, n, n * 2.54);
    printf("%.2lf feet = %.2lf meter\n%.2lf meter = %.2lf feet\n", n, n * 0.3048, n, n / 0.3048);
    printf("%.2lf lb = %.2lf kg\n%.2lf kg = %.2lf lb\n", n, n * 0.4535924, n, n / 0.4535924);
    printf("%.2lf km = %.2lf mile\n%.2lf mile = %.2lf km\n", n, n * 0.6213711922, n, n / 0.6213711922);
    printf("%.2lf km/h = %.2lf mph\n%.2lf mph = %.2lf km/h\n", n, n * 0.621371, n, n / 0.621371);

    return 0;
}