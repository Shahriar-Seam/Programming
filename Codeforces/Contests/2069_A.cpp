#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> b(n - 2), a, temp;

    for (auto &it : b) {
        cin >> it;
    }

    a.push_back(1);

    for (i = 0; i < n - 4; i++) {
        if (b[i] == 1) {
            if (b[i + 1] == 0 && b[i + 2] == 1) {
                cout << "NO\n";

                return;
            }
        }
    }

    cout << "YES\n";
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