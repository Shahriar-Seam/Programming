#include <stdio.h>

int main()
{
    float x, s;

    scanf("%f", &x);

    s = x * x - 5 * x + 12;

    printf("%.2f", s);

    return 0;
}