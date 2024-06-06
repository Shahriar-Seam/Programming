#include <stdio.h>

long long int sum(long long int n)
{
    if (n % 2 == 0) {
        return n / 2;
    }
    else {
        return -(n + 1) / 2;
    }
}

int main()
{
    int t;
    long long int l, r;

    scanf("%d", &t);

    while (t--) {
        scanf("%lld %lld", &l, &r);

        printf("%lld\n", sum(r) - sum(l - 1));
    }

    return 0;
}