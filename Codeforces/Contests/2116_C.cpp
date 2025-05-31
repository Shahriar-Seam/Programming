#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, g = 0, i, j, index, min_val, cnt = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        g = gcd(g, it);
    }

    for (auto &it : v) {
        it /= g;
    }

    sort(v.begin(), v.end());

    while (v[0] != 1) {
        min_val = v[0];
        index = 0;

        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                g = gcd(v[i], v[j]);

                if (g < min_val) {
                    min_val = g;
                    index = i;
                }
            }
        }

        v[index] = min_val;

        swap(v[0], v[index]);

        cnt++;
    }

    cout << v.size() - count(v.begin(), v.end(), 1) + cnt << "\n";
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