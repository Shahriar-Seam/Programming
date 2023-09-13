#include <stdio.h>

int main()
{
    unsigned long long int n, k, r;

    scanf("%llu %llu", &n, &k);

    if (n % 2 == 0) {
        if (k > n / 2) {
            r = 2 * (k - n / 2);
        }
        else {
            r = 2 * k - 1;
        }
    }
    else {
        if (k > n / 2 + 1) {
            r = 2 * (k - n / 2 - 1);
        }
        else {
            r = 2 * k - 1;
        }
    }

    printf("%llu", r);

    return 0;
}