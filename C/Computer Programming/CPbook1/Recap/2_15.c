#include <stdio.h>

int main()
{
    double n1, n2, value;
    char sign;

    printf("Enter a number: ");
    scanf("%lf", &n1);
    printf("Enter another number: ");
    scanf("%lf", &n2);

    value = n1 + n2;
    sign = '+';
    printf("%g %c %g = %g\n", n1, sign, n2, value);

    value = n1 - n2;
    sign = '-';
    printf("%g %c %g = %g\n", n1, sign, n2, value);
    
    value = n1 * n2;
    sign = '*';
    printf("%g %c %g = %g\n", n1, sign, n2, value);
    
    value = n1 / n2;
    sign = '/';
    printf("%g %c %g = %g\n", n1, sign, n2, value);

    return 0;
}