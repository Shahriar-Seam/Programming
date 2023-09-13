#include <stdio.h>

int main()
{
    int a, b, gcd, lcm, x;

    printf("Enter 2 numbers: ");
    scanf("%d %d", &a, &b);

    if (a > b) {
        x = b;
    }
    else {
        x = a;
    }

    for (x; x >= 0; x--) {
        if (a % x == 0 && b % x == 0) {
            gcd = x;
            break;
        }
    }

    lcm = a * b / gcd;

    printf("\nGCD = %d\nLCM = %d\n", gcd, lcm);

    return 0;
}