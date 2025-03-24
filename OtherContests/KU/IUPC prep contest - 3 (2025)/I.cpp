#include <bits/stdc++.h>

using namespace std;

#define int long long

int bleh(int a, int b)
{
    int i;

    for (i = 32; i >= 0; i--) {
        if ((a & (1LL << i)) && !(b & (1LL << i))) {
            return 1LL << i;
        }
    }

    return 0;
}

int bleh2(int k, int count)
{
    return 1LL << (31 - __popcount(k) - count);
}

void solve()
{
    int n, k = 0, i, temp;
    set <int> count;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            k |= bleh(v[i - 1], v[i]);
        }
    }

    for (i = 1; i < n; i++) {
        if (v[i] > v[i - 1]) {
            temp = bleh(v[i], v[i - 1]);

            if (!(temp & k)) {
                count.insert(temp);
            }
        }
    }

    for (i = 0; i < n; i++) {
        v[i] ^= k;
    }

    if (is_sorted(v.begin(), v.end())) {
        cout << k << " " << bleh2(k, count.size()) << "\n";
    }
    else {
        cout << "-1\n";
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