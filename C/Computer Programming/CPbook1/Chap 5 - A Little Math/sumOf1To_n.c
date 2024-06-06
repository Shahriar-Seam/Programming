#include <stdio.h>

int main()
{
    int n, sum;

    printf("Enter a number: ");
    scanf("%d", &n);

    sum = n * (n + 1) / 2;

    printf("Summation of 1 to %d = %d", n, sum);

    return 0;
}