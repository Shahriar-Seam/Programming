// Try to find remainder of a division without using %
#include <stdio.h>

int main()
{
    double num1, num2;

    printf("Enter the dividend and divisor, separated by space.\n");
    scanf("%lf %lf", &num1, &num2);

    double div_result = num1 / num2;
    double quotient = div_result - (int) (num1 / num2);
    double remainder = quotient * num2;

    printf("%.0lf", remainder);

    return 0;
}