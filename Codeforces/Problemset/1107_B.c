#include <stdio.h>

int main()
{
    int n;
    long long int k, x;

    scanf("%d", &n);

    while (n--) {
        scanf("%lld %lld", &k, &x);

        printf("%lld\n", 9 * (k - 1) + x);
    }

    return 0;
}