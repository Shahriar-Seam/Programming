#include <stdio.h>
#include <string.h>

int f_calls = 0;
int fib[50];

int fibonacci(int n)
{
    f_calls++;

    if (fib[n] != 0) {
        return fib[n];
    }

    if (n == 1 || n == 2) {
        return 1;
    }

    fib[n] = fibonacci(n - 1) + fibonacci(n - 2);

    return fib[n];
}

int main()
{
    int n;
    char s[3];

    scanf("%d", &n);

    if (n == 1) {
        strcpy(s, "st");
    }
    else if (n == 2) {
        strcpy(s, "nd");
    }
    else if (n == 3) {
        strcpy(s, "rd");
    }
    else {
        strcpy(s, "th");
    }

    printf("%d%s fibonacci number is %d\n", n, s, fibonacci(n));
    printf("Number of function calls: %d\n", f_calls);

    return 0;
}