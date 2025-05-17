#include <bits/stdc++.h>

using namespace std;

#define int long long

int lg2(int n)
{
    return __lg(2 * n - 1);
}

void solve()
{
    int n, m, a, b, count = 0;

    cin >> n >> m >> a >> b;
    
    cout << min({lg2(min(a, n - a + 1)) + lg2(m), lg2(min(b, m - b + 1)) + lg2(n)}) + 1 << "\n";
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