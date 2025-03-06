#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, p, i, cost = 0;

    cin >> n >> p;

    vector <int> a(n), b(n);
    vector <pair <int, int> > v;

    for (auto &it: a) {
        cin >> it;
    }

    for (auto &it: b) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        v.push_back({b[i], a[i]});
    }

    v.push_back({p, n - 1});

    sort(v.begin(), v.end());

    cost = p;
    n--;

    for (i = 0; i < v.size() && n > 0; i++) {
        if (v[i].second <= n) {
            cost += v[i].second * v[i].first;

            n -= v[i].second;
        }
        else {
            cost += n * v[i].first;

            n = 0;
        }
    }

    cout << cost << "\n";
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