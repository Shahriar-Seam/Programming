#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, i, f;

    cin >> n >> m;

    vector <vector <int> > v(n, vector <int> (m));

    for (auto &it : v) {
        for (auto &jt : it) {
            cin >> jt;
        }
    }

    for (i = 0; i < 50; i++) {
        f = 0;

        for (auto &it : v) {
            for (auto &jt : it) {
                if (jt & (1LL << i)) {
                    f++;

                    break;
                }
            }
        }

        if (f == n) {
            cout << "YES\n";

            return;
        }
    }

    cout << "NO\n";
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