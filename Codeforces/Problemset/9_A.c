#include <stdio.h>

int GCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main()
{
    int a, b, d;

    scanf("%d %d", &a, &b);

    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    d = 6 - a + 1;

    int gcd = GCD(6, d);

    int p = d / gcd;
    int q = 6 / gcd;

    printf("%d/%d", p, q);

    return 0;
}