#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, i, count = 0;

    cin >> n >> m;

    vector <int> v(m), dist;

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = 1; i < m; i++) {
        dist.push_back(v[i] - v[i - 1] - 1);
    }

    dist.push_back(v[0] - 1 + n - v.back());

    sort(dist.begin(), dist.end(), greater <> ());

    for (i = 0; i < dist.size(); i++) {
        if (4 * i < dist[i]) {
            count += 1;

            count += max(0LL, dist[i] - 2 - 4 * i);
        }
    }

    cout << n - count << "\n";
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