#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 1e2 + 10;
vector <double> fact(sz, 1.0);

void factorial()
{
    int i;

    for (i = 2; i < sz; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

void solve()
{
    int n, x, i;
    double sum = 0;

    cin >> n >> x;

    for (i = (n * x + 99) / 100; i <= n; i++) {
        sum += fact[n] / (fact[i] * fact[n - i]);
    }

    cout << sum / (1LL << n) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(2);

    factorial();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}