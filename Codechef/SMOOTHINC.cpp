#include <bits/stdc++.h>

using namespace std;

void lr(vector <int> &v)
{
    int n = v.size(), i;
    vector <int> l_to_r(n, 1), r_to_l(n, 1);

    for (i = 1; i < n; i++) {
        if (l_to_r[i - 1] == 0 || v[i] <= v[i - 1]) {
            l_to_r[i] = 0;
        }
    }

    for (i = n - 2; i >= 0; i--) {
        if (r_to_l[i + 1] == 0 || v[i] >= v[i + 1]) {
            r_to_l[i] = 0;
        }
    }

    for (auto it : l_to_r) {
        cout << it << " ";
    }

    cout << "\n";

    for (auto it : r_to_l) {
        cout << it << " ";
    }

    cout << "\n";
}

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(n), b, l_to_r(n, 1), r_to_l(n, 1);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 1; i < n; i++) {
        b.push_back(v[i] - v[i - 1]);
    }

    lr(v);
    lr(b);
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