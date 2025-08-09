#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x, count = 1;
    int l = -1, r, i;
    string s;

    cin >> n >> x >> s;

    for (i = 0; i < x - 1; i++) {
        if (s[i] == '#') {
            l = i;
        }
    }

    for (i = x, r = n; i < n; i++) {
        if (s[i] == '#') {
            r = i;

            break;
        }
    }

    if (x == 1 || x == n) {
        cout << "1\n";

        return;
    }

    if (l == -1 || r == n) {
        cout << "1\n";

        return;
    }

    if (s[x - 2] == '#' || s[x] == '#') {
        cout << min(x, n - x + 1) << "\n";
    }
    else if (l + 1 > n - r) {
        cout << min(l + 2, n - x + 1) << "\n";
    }
    else {
        cout << min(x, n - r + 1) << "\n";
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