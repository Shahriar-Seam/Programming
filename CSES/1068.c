#include <stdio.h>

int main()
{
    long long int n;

    scanf("%lld", &n);

    while (n != 1) {
        printf("%lld ", n);

        n = (n % 2 == 0) ? n / 2 : (3 * n) + 1;
    }

    puts("1");

    return 0;
}