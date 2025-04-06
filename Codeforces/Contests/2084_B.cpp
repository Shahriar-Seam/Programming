#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, g = 2e18, temp = 0;
    set <int> s;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        g = min(g, it);
    }

    if (count(v.begin(), v.end(), g) > 1) {
        cout << "YES\n";

        return;
    }

    for (auto it : v) {
        if ((it % g == 0) && it != g) {
            s.insert(it);
        }
    }

    for (auto it : s) {
        temp = gcd(temp, it);
    }

    if (temp == g) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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