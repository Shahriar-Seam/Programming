#include <stdio.h>

int gcd(int a, int b)
{
    if (a % b == 0) {
        return b;
    }

    return gcd(a, a % b);
}

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);

    if (a < b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    printf("%d", gcd(a, b));

    return 0;
}