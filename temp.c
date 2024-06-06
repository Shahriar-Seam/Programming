#include <stdio.h>

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int nums[] = {1, 3, 1, 7};
    int x = 1;

    printf("%d\n", gcd(-4, 2));

    return 0;
}