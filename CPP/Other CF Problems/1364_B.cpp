#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, d;

    cin >> n;

    vector <int> p(n), v;

    for (i = 0; i < n; i++) {
        cin >> p[i];
    }

    v.push_back(p[0]);

    if (p[1] > p[0]) {
        d = 1;
    }
    else {
        d = -1;
    }

    for (i = 2; i < n; i++) {
        if (p[i] > p[i - 1] && d == -1) {
            v.push_back(p[i - 1]);

            d = 1;
        }
        else if (p[i] < p[i - 1] && d == 1) {
            v.push_back(p[i - 1]);

            d = -1;
        }
    }

    v.push_back(p.back());

    cout << v.size() << "\n";

    for (auto &it : v) {
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