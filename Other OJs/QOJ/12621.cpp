#include <bits/stdc++.h>

using namespace std;

double sq(double n)
{
    return n * n;
}

void solve()
{
    int n;

    cin >> n;

    cout << 10000 / sq(sin(acos(-1) / n)) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(5);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}