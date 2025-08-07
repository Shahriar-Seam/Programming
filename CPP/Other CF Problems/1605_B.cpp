#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, one;
    string s;

    cin >> n >> s;

    if (is_sorted(s.begin(), s.end())) {
        cout << 0 << "\n";

        return;
    }

    one = count(s.begin(), s.end(), '1');

    vector <int> o, z;

    for (i = n - 1; i >= n - one; i--) {
        if (s[i] == '0') {
            z.push_back(i + 1);
        }
    }

    reverse(z.begin(), z.end());

    for (i = 0; i < n - one; i++) {
        if (s[i] == '1') {
            o.push_back(i + 1);
        }
    }

    cout << 1 << "\n";

    cout << o.size() + z.size() << " ";

    for (auto &it : o) {
        cout << it << " ";
    }

    for (auto &it : z) {
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