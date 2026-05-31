#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, h = 1e18, sum = 0, a, i;

    cin >> n;
    
    for (i = 1; i <= n; i++) {
        cin >> a;

        sum += a;

        h = min(h, sum / i);

        cout << h << " ";
    }

    cout << "\n";
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