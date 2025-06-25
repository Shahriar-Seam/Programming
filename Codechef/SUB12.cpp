#include <bits/stdc++.h>

using namespace std;

#define int long long

bool possible(vector <int> a, vector <int> &b, int n, __int128_t m)
{
    __int128_t sum = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (a[i] + b[i] > m) {
            sum += b[i] - m + a[i];

            a[i] = m;
        }
        else {
            a[i] += b[i];
        }
    }

    for (i = 0; i < n; i++) {
        if (a[i] < m && sum > 0) {
            sum -= (m - a[i]) / 2;

            a[i] += ((m - a[i]) / 2) * 2;
        }
    }

    return sum <= 0;
}

void solve()
{
    int n, val = 0;
    __int128_t l = 0, r = 1e24, m;

    cin >> n;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    l = *max_element(a.begin(), a.end());

    while (l <= r) {
        m = (l + r) / 2;

        if (possible(a, b, n, m)) {
            val = m;

            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    cout << val << "\n";
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