#include <stdio.h>

int main()
{
    int n, s;

    printf("Enter a 4 digit number: ");
    scanf("%d", &n);
    
    s = n % 10 + (n / 10) % 10 + (n / 100) % 10 + (n / 1000) % 10;

    printf("Sum of digits of the number = %d", s);

    return 0;
}