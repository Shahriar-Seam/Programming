#include <bits/stdc++.h>

using namespace std;

#define int long long

bool possible(vector <int> v, int m, int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i += 2) {
        if (i == 0) {
            if (v[i] > v[i + 1]) {
                sum += v[i] - v[i + 1];

                v[i] = v[i + 1];
            }
        }
        else if (i == n - 1) {
            if (v[i] > v[i - 1]) {
                sum += v[i] - v[i - 1];

                v[i] = v[i - 1];
            }
        }
        else {
            if (v[i] > v[i + 1]) {
                sum += v[i] - v[i + 1];

                v[i] = v[i + 1];
            }

            if (v[i] > v[i - 1]) {
                sum += v[i] - v[i - 1];

                v[i] = v[i - 1];
            }
        }
    }

    for (i = 1; i < n - 1; i += 2) {
        if (v[i - 1] + v[i + 1] > v[i]) {
            int temp = v[i - 1] + v[i + 1] - v[i];

            if (temp > v[i + 1]) {
                v[i + 1] = 0;
            }
            else {
                v[i + 1] -= temp;
            }

            sum += temp;
        }
    }

    return sum <= m;
}

void solve()
{
    int n;
    int l, r, m, ops;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    l = 0, r = 1e15;

    while (l <= r) {
        m = (l + r) / 2;

        if (possible(v, m, n)) {
            r = m - 1;

            ops = m;
        }
        else {
            l = m + 1;
        }
    }

    cout << ops << "\n";
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