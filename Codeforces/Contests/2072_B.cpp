#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, count = 0, u = 0, h = 0;
    string s;

    cin >> n >> s;

    for (auto c : s) {
        u += (c == '_');
        h += (c == '-');
    }

    cout << (u >= 1 && h >= 2 ? (u * ((h + 1) / 2) * (h / 2)) : 0) << "\n";
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