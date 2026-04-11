#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, p, q, i;

    cin >> n >> p >> q;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < min(n, p); i++) {
        if (q - v[i] < 0) {
            break;
        }

        q -= v[i];
    }

    cout << i << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}