#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, k, temp, sum = 0;

    cin >> n;

    deque <pair <int, int> > a, b, c, v;

    for (i = 0; i < n; i++) {
        cin >> temp;

        a.push_back({temp, i + 1});
    }

    for (i = 0; i < n; i++) {
        cin >> temp;

        b.push_back({temp, i + 1});
    }

    for (i = 0; i < n; i++) {
        cin >> temp;

        c.push_back({temp, i + 1});
    }

    sort(a.begin(), a.end(), greater <> ());
    sort(b.begin(), b.end(), greater <> ());
    sort(c.begin(), c.end(), greater <> ());

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                if (a[i].second != b[j].second && a[i].second != c[k].second && b[j].second != c[k].second) {
                    sum = max(sum, a[i].first + b[j].first + c[k].first);
                }
            }
        }
    }

    cout << sum << "\n";
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