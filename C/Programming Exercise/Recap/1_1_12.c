#include <stdio.h>

int main()
{
    int n;

    printf("Enter a decimal number: ");
    scanf("%d", &n);

    printf("Octal of %d is %o.\nHexadecimal of %d is %x.\n", n, n, n, n);

    return 0;
}