#include <stdio.h>

unsigned long long int power(unsigned long long int n)
{
    unsigned long long int i, result = 1;

    for (i = 0; i < n; i++) {
        result *= n;
    }

    return result;
}

int main()
{
    unsigned long long int a, b, i, f = 0;

    scanf("%llu", &b);

    for (i = 1; i <= 16; i++) {
        if (power(i) == b) {
            f = 1;
            break;
        }
    }

    f ? printf("%llu", i) : printf("-1");

    return 0;
}