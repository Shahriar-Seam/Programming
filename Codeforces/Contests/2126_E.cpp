#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, g, f = 1;

    cin >> n;

    vector <int> p(n), s(n), v(n);

    for (auto &it : p) {
        cin >> it;
    }

    for (auto &it : s) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        v[i] = max(p[i], s[i]);
    }

    for (i = 0, g = 0; i < n; i++) {
        g = gcd(g, v[i]);

        if (p[i] != g) {
            f = 0;

            break;
        }
    }

    for (i = n - 1, g = 0; i >= 0; i--) {
        g = gcd(g, v[i]);

        if (s[i] != g) {
            f = 0;

            break;
        }
    }

    cout << (f ? "YES" : "NO") << "\n";
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