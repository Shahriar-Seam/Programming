#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, d, root1, root2;

    scanf("%lf %lf %lf", &a, &b, &c);

    d = pow(b, 2) - 4 * a * c;

    root1 = (-b + sqrt(d)) / (2 * a);
    root2 = (-b - sqrt(d)) / (2 * a);

    printf("Root 1 = %g\nRoot 2 = %g\n", root1, root2);

    return 0;
}