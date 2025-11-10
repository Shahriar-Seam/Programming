#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, y = 0, b = 0, i = 0;
    string s;
    map <pair <int, int>, int> indices;

    cin >> n;

    vector <pair <int, int> > v(n);
    s.resize(n);

    for (auto &it : v) {
        cin >> it.first >> it.second;

        indices[it] = i++;
    }

    sort(v.begin(), v.end());

    y = v[0].second;
    s[indices[v[0]]] = '0';

    for (i = 1; i < n; i++) {
        if (v[i].first < y) {
            b = v[i].second;

            s[indices[v[i]]] = '1';
        }
        else if (v[i].first < b) {
            y = v[i].second;

            s[indices[v[i]]] = '0';
        }
    }

    cout << s << "\n";
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