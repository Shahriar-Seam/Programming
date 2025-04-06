#include <stdio.h>
#include <stdint.h>

#define int long long

void solve()
{
    char s[10];
    int i, n, triples = 1;

    scanf(" %s", s);

    for (i = 0; s[i] != '\0'; i++) {
        n = s[i] - '0';

        triples *= ((n + 1) * (n + 2)) / 2;
    }

    printf("%lld\n", triples);
}

int32_t main()
{
    int32_t t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}