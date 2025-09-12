#include <bits/stdc++.h>

using namespace std;

#define int long long

int len(int n)
{
    int l = 0;

    while (n) {
        l++;

        n /= 10;
    }

    return l;
}

void solve()
{
    int x, y = 0, l;

    cin >> x;

    l = len(x);

    while (l--) {
        y *= 10;
        y += 9;
    }

    if (len(y - x) < len(x)) {
        y *= 10;
        y += 9;
    }

    cout << y - x << "\n";
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