#include <bits/stdc++.h>

using namespace std;

void recurse(int n, int k, int p, int d, map <int, int> &mp)
{
    if (n == 0 || n < k) {
        return;
    }

    if (mp.find(n) == mp.end()) {
        if (n % 2 == 0) {
            mp[n] = d + 1;

            recurse(n / 2, k, n, d + 1, mp);
        }
        else {
            mp[n] = d + 1;

            recurse(n / 2, k, n, d + 1, mp);
            recurse(n / 2 + 1, k, n, d + 1, mp);
        }
    }
}

void solve()
{
    int n, k;
    map <int, int> mp;

    mp[0] = 0;

    cin >> n >> k;

    recurse(n, k, 0, -1, mp);

    if (mp[k] == 0 && k != n) {
        cout << -1 << "\n";
    }
    else {
        cout << mp[k] << "\n";
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