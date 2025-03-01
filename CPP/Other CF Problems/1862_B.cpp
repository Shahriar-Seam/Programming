#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> b(n), a;

    for (auto &it : b) {
        cin >> it;
    }

    a.push_back(b[0]);

    for (i = 1; i < n; i++) {
        if (b[i] >= b[i - 1]) {
            a.push_back(b[i]);
        }
        else {
            a.push_back(b[i]);
            a.push_back(b[i]);
        }
    }

    cout << a.size() << "\n";

    for (auto it : a) {
        cout << it << " ";
    }

    cout << "\n";
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