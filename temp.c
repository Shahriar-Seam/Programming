#include <stdio.h>

int main()
{
    long long n;

    scanf("%lld", &n);

    printf("%lld ", n);

    while (n != 1) {
        if (n % 2 == 1) {
            n = 3 * n + 1;
        }
        else {
            n /= 2;
        }

        printf("%lld ", n);
    }

    return 0;
}