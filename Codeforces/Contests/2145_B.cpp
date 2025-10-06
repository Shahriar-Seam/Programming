#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, l, r;
    string s;

    cin >> n >> k >> s;

    string v(n, '+');

    l = 0, r = n - 1;

    sort(s.begin(), s.end());

    for (i = 0; i < k && l <= r; i++) {
        if (s[i] == '0') {
            v[l++] = '-';
        }
        else if (s[i] == '1') {
            v[r--] = '-';
        }
        else {
            v[l++] = '?';
            v[r--] = '?';
        }
    }

    if (k == n) {
        v = string(n, '-');
    }

    cout << v << "\n";
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