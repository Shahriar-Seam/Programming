#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

int bin_exp(int b, int p, int m = mod)
{
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * b) % m;
        }

        b = (b * b) % m;

        p >>= 1;
    }

    return result % m;
}

void solve()
{
    int n, i, count1 = 0, count2 = 0;

    cin >> n;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (a[i] <= b[i]) {
            count1++;
        }
        if (a[i] >= b[i]) {
            count2++;
        }
    }

    cout << bin_exp(2, min(count1, count2)) << "\n";
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
