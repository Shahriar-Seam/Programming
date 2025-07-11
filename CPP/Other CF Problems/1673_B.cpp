#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int i, j, n, len;
    string s;
    map <int, int> mp;

    cin >> s;

    n = s.size();

    for (i = 0; i < n; i++) {
        mp[s[i]]++;

        if (mp[s[i]] > 1) {
            break;
        }
    }

    len = i;

    for (i, j = 0; i < n; i++, j++) {
        j %= len;

        if (s[i] != s[j]) {
            cout << "NO\n";

            return;
        }
    }

    cout << "YES\n";
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