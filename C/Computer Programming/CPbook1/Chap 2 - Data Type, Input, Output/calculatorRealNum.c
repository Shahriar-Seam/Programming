#include <stdio.h>

int main()
{
    double num1, num2, sum, sub, mul, div;
    char plus = '+', minus = '-', multi = '*', division = '/';

    printf("Enter a number: ");
    scanf("%lf", &num1);
    printf("Enter another number: ");
    scanf("%lf", &num2);

    sum = num1 + num2;
    sub = num1 - num2;
    mul = num1 * num2;
    div = num1 / num2;



    printf("%.2lf %c %.2lf = %.2lf\n", num1, plus, num2, sum);
    printf("%.2lf %c %.2lf = %.2lf\n", num1, minus, num2, sub);
    printf("%.2lf %c %.2lf = %.2lf\n", num1, multi, num2, mul);
    printf("%.2lf %c %.2lf = %.2lf\n", num1, division, num2, div);

    return 0;
}