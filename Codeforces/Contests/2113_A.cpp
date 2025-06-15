#include <bits/stdc++.h>

using namespace std;

#define int long long

int max(int a, int b)
{
    return a > b ? a : b;
}

int ceil_div(int a, int b)
{
    return (a + b - 1) / b;
}

void solve()
{
    int k, x, y, a, b;
    int temp1, temp2;

    cin >> k >> a >> b >> x >> y;

    temp1 = max(0, ceil_div((k - b + 1), y));
    temp2 = max(0, ceil_div((k - a + 1), x));
    
    temp1 += max(0, ceil_div((k - temp1 * y - a + 1), x));
    
    temp2 += max(0, ceil_div((k - temp2 * x - b + 1), y));

    cout << max(0, max(temp1, temp2)) << "\n";
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