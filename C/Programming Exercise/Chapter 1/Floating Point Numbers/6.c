#include <stdio.h>
#include <math.h>

int main()
{
    float x, result;

    scanf("%f", &x);

    result = pow(x, 5) - 3 * pow(x, 4) - 7 * pow(x, 3) + 13 * pow(x, 2) + 3742;

    printf("%.2f", result);

    return 0;
}