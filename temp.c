#include <stdio.h>
#include <string.h>

int main()
{
    int a = 10, b = 20, c = 0;
    float f = 15;

    c = a * 1.5 / b + a / b + b * f / 10 + b / 15 + b / 12.5;

    printf("%d", c);

    return 0;
}