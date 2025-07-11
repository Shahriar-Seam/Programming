#include <bits/stdc++.h>

using namespace std;

#define int long long

__int128_t sq(__int128_t n)
{
    return n * n;
}

__int128_t area(vector <int> &v, __int128_t m)
{
    __int128_t a = 0;

    for (auto &it : v) {
        a += sq(it + 2 * m);
    }

    return a;
}

void solve()
{
    int n, C;
    __int128_t l = 1, r = 1e10, m, a, c;
    int w = 1;

    cin >> n >> C;

    c = C;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    while (l <= r) {
        m = (l + r) / 2;

        a = area(v, m);

        if (a >= c) {
            w = m;

            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    cout << w << "\n";
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