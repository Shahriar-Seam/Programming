#include <bits/stdc++.h>

using namespace std;

#define int long long

bool fair(int n)
{
    int temp = n;

    while (temp > 0) {
        if (((temp % 10) > 0) && (n % (temp % 10)) != 0) {
            return false;
        }

        temp /= 10;
    }

    return true;
}

void solve()
{
    int n, i;

    cin >> n;

    for (i = n; i < n + 2520; i++) {
        if (fair(i)) {
            cout << i << "\n";

            return;
        }
    }

    cout << -1 << "\n";
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