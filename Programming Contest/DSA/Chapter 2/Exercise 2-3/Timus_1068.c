#include <stdio.h>

int main()
{
    long long int n, sum;

    scanf("%lld", &n);

    if (n < 0) {
        n = -n;

        sum = -(n * (n + 1) / 2 - 1);
    }
    else {
        sum = n * (n + 1) / 2;
    }

    if (n == 0) {
        sum = 1;
    }

    printf("%lld\n", sum);

    return 0;
}