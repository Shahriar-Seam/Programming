#include <stdio.h>

int main()
{
    int t, i;
    long long int n, m;

    scanf("%d", &t);

    for (i = 1; i <= t; i++) {
        scanf("%lld %lld", &n, &m);
        
        printf("Case %d: %lld\n", i, (n / 2) * m);
    }
    return 0;
}