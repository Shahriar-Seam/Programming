#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    string a, b, s, t;
    vector <pair <int, pair <int, int> > > v;

    cin >> n >> a >> b;

    a += '0';
    b += '0';

    for (i = 0; i < n; i += 2) {
        s = a.substr(i, 2);
        t = b.substr(i, 2);

        if (s != t) {
            if (s[0] == t[1] && s[1] == t[0]) {
                v.push_back({2, {i + 1, i + 2}});
            }
            else if (s[0] != t[0] && s[1] != t[1]) {
                v.push_back({1, {i + 1, i + 2}});
            }
            else {
                if (s[0] != t[0]) {
                    v.push_back({1, {i + 1, i + 1}});
                }
                else {
                    v.push_back({1, {i + 2, i + 2}});
                }
            }
        }
    }

    cout << v.size() << "\n";

    for (auto &it : v) {
        cout << it.first << " " << it.second.first << " " << it.second.second << "\n";
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