#include <stdio.h>
#include <stdlib.h>

#define read(n, m) scanf("%lld %lld", &(n), &(m))

long long int min(long long int a, long long int b)
{
    return a < b ? a : b;
}

int main()
{
    int t;
    long long int x, y, a, b, dollars;

    scanf("%d", &t);

    while (t--) {
        read(x, y);
        read(a, b);

        dollars = min(abs(x - y) * a + min(x, y) * b, x * a + y * a);

        printf("%lld\n", dollars);
    }

    return 0;
}