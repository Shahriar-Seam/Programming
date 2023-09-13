#include <stdio.h>

int main()
{
    int a, b, gcd, lcm, num1, num2, temp;

    scanf("%d %d", &a, &b);

    num1 = a;
    num2 = b;

    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }

    if (a == 0) {
        gcd = a;
    }
    else if (b == 0) {
        gcd = b;
    }
    else {
        while (b != 0) {
            temp = b;
            b = a % b;
            a = temp;
        }

        gcd = a;
    }

    if (gcd == 0) {
        printf("GCD = %d\nThe numbers don't have LCM.\n", gcd);
    }
    else {
        lcm = num1 * num2 / gcd;
        printf("GCD = %d\nLCM = %d\n", gcd, lcm);
    }

    return 0;
}