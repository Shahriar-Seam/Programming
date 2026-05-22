#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    int i, f = 1, l, r, n;

    cin >> s;

    n = s.size();

    s.push_back('0');

    for (l = 1; l < n; l++) {
        if (s[l] == s[l - 1]) {
            break;
        }
    }

    for (r = n - 2; r >= 0; r--) {
        if (s[r] == s[r + 1]) {
            break;
        }
    }

    if (r < l) {
        r = n - 1;
    }

    if (l == n) {
        cout << "YES\n";
    }
    else {
        for (i = l; i < r; i++) {
            if (s[i] == s[i + 1]) {
                f = 0;
            }
        }

        cout << (f ? "YES" : "NO") << "\n";
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