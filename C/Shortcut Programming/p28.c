#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, root1, root2;

    printf("Enter values of a, b & c: ");
    scanf("%f %f %f", &a, &b, &c);

    root1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    root2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

    printf("Root1 = %7.2f  Root2 = %7.2f\n", root1, root2);

    return 0;
}