#include <stdio.h>

int factorial(int n)
{
    int i, f = 1;

    for (i = 1; i <= n; i++) {
        f *= i;
    }

    return f;
}

int main()
{
    int n, fact;

    scanf("%d", &n);

    if (n == 0) {
        printf("0! = 1");
    }

    else {
        fact = factorial(n);
        printf("%d! = %d", n, fact);
    }

    return 0;
}