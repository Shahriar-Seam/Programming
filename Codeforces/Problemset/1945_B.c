#include <stdio.h>

int main()
{
    int t;
    long long int a, b, m;

    scanf("%d", &t);

    while (t--) {
        scanf("%lld %lld %lld", &a, &b, &m);

        printf("%lld\n", 2 + m / a + m / b);
    }

    return 0;
}