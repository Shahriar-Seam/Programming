#include <stdio.h>

int main()
{
    float b, h, a;

    scanf("%f %f", &b, &h);

    a = b * h / 2;

    printf("%.2f\n", a);

    return 0;
}