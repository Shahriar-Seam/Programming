#include <stdio.h>
#include <math.h>

const float e = 2.718281828;

int main()
{
    float x, s;

    scanf("%f", &x);

    s = pow(e, (5 * x - 1));

    printf("%.2f", s);

    return 0;
}