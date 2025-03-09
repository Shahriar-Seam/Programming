#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int a, b;

    cin >> a >> b;

    if (a < b) {
        swap(a, b);
    }

    if (a % b == 0 && (a / (1LL << __builtin_ctzll(a)) == b / (1LL << __builtin_ctzll(b)))) {
        cout << ((__builtin_ctzll(a) - __builtin_ctzll(b)) + 2) / 3 << "\n";
    }
    else {
        cout << -1 << "\n";
    }
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