#include <stdio.h>

int main()
{
    int t;
    long long int n, sum;

    scanf("%d", &t);

    while (t--) {
        scanf("%lld", &n);

        sum = 0;

        while (n > 0) {
            sum += n;
            n >>= 1;
        }

        printf("%lld\n", sum);
    }

    return 0;
}