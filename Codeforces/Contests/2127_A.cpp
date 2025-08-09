#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    if (count(v.begin(), v.end(), 0) > 0) {
        cout << "NO\n";
    }
    else {
        sort(v.begin(), v.end());

        if (v[n - 1] == -1) {
            cout << "YES\n";
        }
        else {
            for (i = 0; i < n; i++) {
                if (v[i] == -1) {
                    v[i] = v[n - 1];
                }
            }

            if (count(v.begin(), v.end(), v[n - 1]) == n) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
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