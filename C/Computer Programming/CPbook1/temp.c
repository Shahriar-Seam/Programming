// This file is for testing codes...

#include <stdio.h>

int main()
{
    float num1, num2;

    printf("Enter 2 numbers: ");
    scanf("%f %f", &num1, &num2);

    printf("%g + %g = %g\n", num1, num2, num1 + num2);
    printf("%g - %g = %g\n", num1, num2, num1 - num2);
    printf("%g * %g = %g\n", num1, num2, num1 * num2);
    printf("%g / %g = %g\n", num1, num2, num1 / num2);

    return 0;
}