#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int l, r, sum, prev, i;

    cin >> l >> r;

    sum = l + l + 1;
    prev = l + 1;

    for (i = 2; sum <= r; i++) {
        sum = sum + prev;

        prev = sum - prev;
    }

    cout << i << "\n";
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