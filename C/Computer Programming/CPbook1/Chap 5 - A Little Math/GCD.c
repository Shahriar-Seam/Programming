#include <stdio.h>

int main()
{
    int num1, num2, x, gcd;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if (num1 < num2) {
        x = num1;
    }
    else {
        x = num2;
    }
    for (x; x > 0; x--) {
        if (num1 % x == 0 && num2 % x == 0) {
            gcd = x;
            break;
        }
    }

    printf("%d", gcd);

    return 0;
}