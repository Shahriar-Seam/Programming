#include <bits/stdc++.h>

using namespace std;

void recurse(int depth, int l, int r, vector <int> &v, vector <int> &d)
{
    if (l > r) {
        return;
    }

    int i, max_idx = -1, max_val = -1;

    for (i = l; i <= r; i++) {
        if (v[i] > max_val) {
            max_val = v[i];
            max_idx = i;
        }
    }

    d[v[max_idx]] = depth;

    recurse(depth + 1, l, max_idx - 1, v, d);
    recurse(depth + 1, max_idx + 1, r, v, d);
}

void solve()
{
    int n;

    cin >> n;

    vector <int> v(n), d(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    recurse(0, 0, n - 1, v, d);

    for (auto &it : v) {
        cout << d[it] << " ";
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