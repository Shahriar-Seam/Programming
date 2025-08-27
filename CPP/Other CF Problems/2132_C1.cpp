#include <bits/stdc++.h>

using namespace std;

#define int long long

int bin_exp(int b, int p)
{
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = result * b;
        }

        b = b * b;

        p >>= 1;
    }

    return result;
}

void solve()
{
    int n, cost = 0, i, p = 1;
    vector <int> v;

    cin >> n;

    while (n > 0) {
        v.push_back(n % 3);

        n /= 3;
    }

    for (i = 0; i < v.size(); i++) {
        cost += v[i] * (bin_exp(3, i + 1) + i * bin_exp(3, i - 1));
    }

    cout << cost << "\n";
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