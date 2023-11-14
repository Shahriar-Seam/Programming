#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, A, B, C;

    printf("Enter the lengths of the sides: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    A = acos((b * b + c * c - a * a) / (2 * b * c));
    B = acos((a * a + c * c - b * b) / (2 * a * c));
    C = acos((a * a + b * b - c * c) / (2 * a * b));

    printf("A = %g\nB = %g\nC = %g\n", A, B, C);

    return 0;
}