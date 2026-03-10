#include <bits/stdc++.h>

using namespace std;

#define int long long

int bin_search(vector <pair <int, int> > &p, int v, int r)
{
    int l = 0, m, index = -1;

    while (l <= r) {
        m = (l + r) / 2;

        if (p[m].first < v) {
            l = m + 1;

            index = m;
        }
        else {
            r = m - 1;
        }
    }

    return index + 1;
}

void solve()
{
    int n, i, index, count = 0;

    cin >> n;

    vector <int> v(n);
    vector <pair <int, int> > p;

    for (i = 0; i < n; i++) {
        cin >> v[i];

        if (v[i] < i + 1) {
            p.push_back({i + 1, v[i]});
        }
    }

    sort(p.begin(), p.end());

    for (i = 0; i < p.size(); i++) {
        index = bin_search(p, p[i].second, i - 1);

        count += index;
    }

    cout << count << "\n";
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
