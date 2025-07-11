#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, j, count = 0;

    cin >> n;

    vector <pair <int, int> > v(n + 1);

    for (i = 1; i <= n; i++) {
        cin >> v[i].first;

        v[i].second = i;
    }

    v[0] = {0, 0};

    sort(v.begin(), v.end());

    for (i = 1; i <= n; i++) {
        for (j = v[i]; j <= 2 * n; j += v[i]) {
            if (v[i].first * v[j].first == v[i].second + v[j].second) {
                count++;
            }

            if (v[i].first + v[j].first > 2 * n) {
                break;
            }
        }
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