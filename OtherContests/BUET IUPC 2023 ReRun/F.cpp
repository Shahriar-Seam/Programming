#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, p, q, x, y, cost1 = 0, cost2 = 0, i;

    cin >> n >> p >> q >> x >> y;

    for (i = 0; i < n; i++) {
        cost1 += p - i * x;
    }
    
    for (i = 0; i < n; i++) {
        cost2 += q - i * y;
    }

    cout << min(cost1, cost2) << "\n";
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