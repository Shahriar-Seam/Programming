#include <stdio.h>

void solve()
{
    long long n, k, num_arrays = 1, i;

    scanf("%lld %lld", &n, &k);

    for (i = 0; i < k; i++) {
        num_arrays = (num_arrays * n) % ((int) 1e9 + 7);
    }

    printf("%lld\n", num_arrays);
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}