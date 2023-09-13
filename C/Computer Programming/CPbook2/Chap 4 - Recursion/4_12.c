#include <stdio.h>

int count = 0;

int factorial(int n)
{
    count++;

    if (n == 0) 
        return 1;
    
    return n * factorial(n - 1);
}

int main()
{
    int n;

    scanf("%d", &n);

    if (n < 0) {
        printf("Undefined.\n");
        return 0;
    }

    printf("Factorial of %d is %d\n", n, factorial(n));
    printf("Count = %d\n", count);

    return 0;
}