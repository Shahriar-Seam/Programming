#include <stdio.h>

int main()
{
    int a = 12, b = 17;

    a = a - b;
    b = a + b;
    a = b - a;

    printf("a = %d, b = %d\n", a, b);

    return 0;
}