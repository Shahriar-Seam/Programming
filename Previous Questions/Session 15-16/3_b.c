#include <stdio.h>

int GCD(int a, int b)
{
    int temp, gcd;

    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }

    if (a == 0 || b == 0) {
        gcd = 0;
    }
    else {
        while (b != 0) {
            temp = b;
            b = a % b;
            a = temp;
        }

        gcd = a;
    }
}

int main()
{
    int a, b, gcd;

    scanf("%d %d", &a, &b);

    gcd = GCD(a, b);

    printf("GCD = %d\n", gcd);

    return 0;
}