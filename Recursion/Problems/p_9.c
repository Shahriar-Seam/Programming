// Write a recursive function that finds the gcd of
// two non-negative integers.

#include <stdio.h>

int GCD(int a, int b)
{
    if (a % b == 0) {
        return b;
    }
    else {
        GCD(b, a % b);
    }
}

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);

    if (b > a) {
        int temp = b;
        b = a;
        a = temp;
    }

    printf("%d\n", GCD(a, b));

    return 0;
}