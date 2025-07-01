#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int bin_search(vector <int> &a, int k)
{
    int l = 0, r = a.size() - 1, m, index = a.size();

    while (l <= r) {
        m = (l + r) / 2;

        if (a[m] > k) {
            index = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return index;
}

void solve()
{
    int n, i, num_ways = 1;

    cin >> n;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (i = n - 1; i >= 0; i--) {
        num_ways *= max(0LL, n - bin_search(a, b[i]) - (n - i - 1));

        num_ways %= mod;
    }

    cout << num_ways << "\n";
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