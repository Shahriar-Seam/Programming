#include <bits/stdc++.h>

using namespace std;

#define int long long

long double nCr(int n, int r)
{
    if (r > n) {
        return 0;
    }

    if (r == 0 || n == r) {
        return 1;
    }

    long double res = 0;

    for (int i = 0; i < r; i++) {
        res += log(n - i) - log(i + 1);
    }

    return exp(res);
}

void solve()
{
    int k, m;

    cout << nCr(1e18, 1796) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}