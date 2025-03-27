#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define int long long
const int mod = 998244353;
const int sz = 2e5 + 5;

int *fact;

void factorial()
{
    int i;

    fact = (int *) malloc(sz * sizeof(int));

    fact[0] = fact[1] = 1;

    for (i = 2; i < sz; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

void solve()
{
    char s[sz];
    int i, n, ops = 0, num = 1, cnt = 1;

    scanf(" %s", s);

    n = strlen(s);

    for (i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
        }
        else {
            ops++;

            num = (cnt * num * fact[cnt]) % mod;

            cnt = 1;
        }
    }

    ops++;

    num = (num * fact[cnt]) % mod;

    ops = n - ops;

    printf("%lld %lld\n", ops, num);
}

int32_t main()
{
    factorial();

    int32_t t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}