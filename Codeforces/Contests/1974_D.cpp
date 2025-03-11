#include <bits/stdc++.h>

using namespace std;

void count(int c, int r, set <pair <int, int> > &s)
{
    int x, y;

    for (x = 0; x <= r; x++) {
        for (y = 0; 1LL * x * x + y * y <= 1LL * r * r; y++) {
            if (1LL * x * x + y * y <= 1LL * r * r) {
                s.insert({c + x, y});
                s.insert({c - x, y});
                s.insert({c + x, -y});
                s.insert({c - x, -y});
            }
        }
    }
}

void solve()
{
    int n, m, i;
    set <pair <int, int> > s;

    cin >> n >> m;

    vector <int> x(n), r(n);

    for (auto &it : x) {
        cin >> it;
    }

    for (auto &it : r) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        count(x[i], r[i], s);
    }

    cout << s.size() << "\n";
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