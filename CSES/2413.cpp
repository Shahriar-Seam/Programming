#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;

void solve()
{
    int n, a, b, prev_a, prev_b, i;

    cin >> n;

    prev_a = prev_b = 1;

    for (i = 1; i < n; i++) {
        a = (4 * prev_a + prev_b) % mod;
        b = (2 * prev_b + prev_a) % mod;

        prev_a = a;
        prev_b = b;
    }

    cout << (a + b) % mod << "\n";
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