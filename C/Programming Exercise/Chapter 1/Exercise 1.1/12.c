#include <stdio.h>

int main()
{
    int n;

    printf("Enter a decimal number: ");
    scanf("%d", &n);
    printf("Octal = %o\n", n);
    printf("Hexadecimal = %x\n", n);

    return 0;
}