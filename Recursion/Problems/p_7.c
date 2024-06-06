// Write a recursive program to compute nth 
// fibonacci number. 1st and 2nd fibonacci 
// numbers are 0, 1.

#include <stdio.h>

int fibonacci(int i)
{
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }

    return fibonacci(i - 1) + fibonacci(i - 2);
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("%d\n", fibonacci(n));

    return 0;
}