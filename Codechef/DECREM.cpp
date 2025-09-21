#include <bits/stdc++.h>

using namespace std;

bool sorted(vector <int> &v)
{
    int i;

    for (i = 1; i < v.size(); i++) {
        if (v[i] >= v[i - 1]) {
            return false;
        }
    }

    return true;
}

void solve()
{
    int l, r;

    cin >> l >> r;

    if (l * 2 <= r) {
        cout << -1 << "\n";
    }
    else {
        cout << r << "\n";
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