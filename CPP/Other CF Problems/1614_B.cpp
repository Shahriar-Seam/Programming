#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, j, time = 0;

    cin >> n;

    vector <pair <int, int> > v(n);
    vector <int> pos(n), visits(n);

    for (i = 0; i < n; i++) {
        cin >> v[i].first;

        v[i].second = i;
    }

    sort(v.begin(), v.end(), greater <pair <int, int> > ());

    for (i = 0, j = 1; i < n; i++) {
        if (i % 2 == 0) {
            pos[v[i].second] = j;

            visits[v[i].second] = v[i].first;
        }
        else {
            pos[v[i].second] = -j;

            visits[v[i].second] = v[i].first;

            j++;
        }
    }

    for (i = 0; i < n; i++) {
        time += visits[i] * abs(pos[i]);
    }

    cout << 2 * time << "\n";

    cout << 0 << " ";

    for (auto it : pos) {
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