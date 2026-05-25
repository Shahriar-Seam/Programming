#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, sgn = 1;

    cin >> n;

    vector <int> v(n), b;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = n - 1; i >= 0; i--) {
        if (v[i] * sgn > 0) {
            b.push_back(i + 1);

            sgn *= -1;
        }
    }

    cout << b.size() << "\n";

    for (auto &it : b) {
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