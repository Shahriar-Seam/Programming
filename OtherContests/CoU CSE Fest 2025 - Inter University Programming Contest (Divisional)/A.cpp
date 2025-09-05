#include <bits/stdc++.h>

using namespace std;

#define int long long

int f(int n)
{
    return n <= 1 ? 1 : f(n - 1) * n;
}

void solve()
{
    int n;

    cin >> n;

    cout << f(n - 1) << "\n";
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