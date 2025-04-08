#include <bits/stdc++.h>

using namespace std;

int is_prime(int n)
{
    int i;

    if (n < 2) {
        return 0;
    }
    else if (n == 2) {
        return 1;
    }
    else if (n % 2 == 0) {
        return 0;
    }

    for (i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

void solve()
{
    int x, k;

    cin >> x >> k;

    if (k >= 2 && x != 1) {
        cout << "NO" << "\n";
    }
    else if (k == 2 && x == 1) {
        cout << "YES\n";
    }
    else {
        cout << (is_prime(x) ? "YES" : "NO") << "\n";
    }
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