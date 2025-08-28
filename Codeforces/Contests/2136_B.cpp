#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, j, max = 0, max_i = -1;
    string s;
    set <int> ss;

    cin >> n >> k >> s;

    vector <int> v(n), indices(n + 1);

    for (i = 0, j = 1; i < n; i++) {
        if (s[i] == '1') {
            v[i] = j++;
        }
    }

    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            v[i] = j++;
        }
    }

    for (i = 0; i < n; i++) {
        indices[v[i]] = i;
    }

    for (i = 0; i < k; i++) {
        ss.insert(v[i]);
    }

    if (s[indices[*ss.rbegin()]] == '1') {
        cout << "NO\n";

        return;
    }

    for (i; i < n; i++) {
        ss.insert(v[i]);

        ss.erase(v[i - k]);

        if (s[indices[*ss.rbegin()]] == '1') {
            cout << "NO\n";

            return;
        }
    }

    cout << "YES\n";

    for (auto &it : v) {
        cout << it << " ";
    }

    cout << "\n";
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