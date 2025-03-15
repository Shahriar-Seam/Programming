#include <bits/stdc++.h>

using namespace std;

int XOR(string &s)
{
    int i, x = 0;

    for (i = 0; i < s.length(); i++) {
        x ^= (s[i] - '0');
    }

    return x;
}

void solve()
{
    int n, m, r = 0, c = 0, i, j;

    cin >> n >> m;

    vector <string> v(n);
    string s;

    for (auto &it : v) {
        cin >> it;
    }

    for (auto &it : v) {
        r += XOR(it);
    }

    for (i = 0; i < m; i++) {
        s = "";

        for (j = 0; j < n; j++) {
            s += v[j][i];
        }

        c += XOR(s);
    }

    cout << max(r, c) << "\n";
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