#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, k;

    cin >> n >> m >> k;

    if (k <= n && k <= m) {
        cout << k * k << "\n";
    }
    else {
        cout << min({n, m, k}) * (n + m + k - max({n, m, k}) - min({n, m, k})) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}