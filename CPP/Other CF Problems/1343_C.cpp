#include <bits/stdc++.h>

using namespace std;

#define int long long

int sign(int n)
{
    if (n < 0) {
        return -1;
    }
    else {
        return 1;
    }
}

void solve()
{
    int n, l, r, max_val = -1e16 + 5, sum = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (l = 0, r = 0; r < n; ) {
        if (sign(v[l]) == sign(v[r])) {
            max_val = max(max_val, v[r]);

            r++;
        }
        else {
            sum += max_val;

            max_val = -1e16 + 5;

            l = r;
        }
    }

    sum += max_val;

    cout << sum << "\n";
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