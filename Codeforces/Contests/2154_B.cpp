#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, max_v = 0, count = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        max_v = max(max_v, v[i]);

        if (i & 1) {
            v[i] = max_v;
        }
    }

    for (i = 0; i < n; i += 2) {
        if (i == 0) {
            if (v[i] == v[i + 1]) {
                v[i]--;

                count++;
            }

            continue;
        }

        if (v[i] >= v[i - 1]) {
            count += v[i] - v[i - 1] + 1;

            v[i] = v[i - 1] - 1;
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