#include <bits/stdc++.h>

using namespace std;

#define int long long

int min(int a, int b)
{
    return a < b ? a : b;
}

void solve()
{
    int n, k, i, j, _min = 4e18, temp;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    v.push_back(0);
    v.push_back(2e18);

    sort(v.begin(), v.end());

    if (k >= 3) {
        cout << 0 << "\n";
    }
    else if (k == 1) {
        for (i = 1; i <= n; i++) {
            _min = min(_min, v[i] - v[i - 1]);
        }

        cout << _min << "\n";
    }
    else {
        for (i = 1; i <= n; i++) {
            for (j = i + 1; j <= n; j++) {
                temp = abs(v[i] - v[j]);

                auto it = lower_bound(v.begin(), v.end(), temp);

                _min = min(_min, abs(*it - temp));

                if (it != v.begin()) {
                    _min = min(_min, abs(*--it - temp));
                }
            }
        }

        cout << _min << "\n";
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