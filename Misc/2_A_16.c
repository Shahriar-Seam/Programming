#include <stdio.h>

int main()
{
    int a = 12, b = 17;

    a = a + b;
    b = a - b;
    a = a - b;

    printf("%d %d", a, b);

    return 0;
}