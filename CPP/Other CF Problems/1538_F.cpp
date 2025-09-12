#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int l, r, count = 0, d = 1, i;

    cin >> l >> r;

    for (i = 0; i < 11; i++) {
        count += r / d - l / d;

        d *= 10;
    }

    cout << count << "\n";
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