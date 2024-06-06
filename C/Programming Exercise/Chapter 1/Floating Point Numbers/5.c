#include <stdio.h>

const float pi = 3.14159;

int main()
{
    float r, a, v;

    scanf("%f", &r);

    a = 4 * pi * r * r;
    v = 4 * pi * r * r * r / 3;

    printf("Area = %.2f\nVolume = %.2f\n", a, v);

    return 0;
}