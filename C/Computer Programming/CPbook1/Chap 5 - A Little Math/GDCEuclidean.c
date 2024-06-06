#include <stdio.h>

int main()
{
    int num1, num2, a, b, r, gcd;

    scanf("%d%d", &num1, &num2);

    if (num1 < num2) {
        a = num2;
        b = num1;
    }
    else {
        a = num1;
        b = num2;
    }

    while (b != 0)
    {
        r = a % b;
        if (r == 0) {
            gcd = b;
            break;
        }
        a = b;
        b--;
    }
    printf("GCD = %d\n", gcd);
    // printf("LCM = %d\n", (num1 * num2 / gcd));
    

    return 0;
}