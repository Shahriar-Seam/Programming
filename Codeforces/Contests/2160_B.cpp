#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, val = 1;

    cin >> n;

    vector <int> a(n), b(n);

    for (auto &it : b) {
        cin >> it;
    }

    a[0] = 1;

    for (i = 1; i < n; i++) {
        if (i - b[i] + b[i - 1] >= 0LL) {
            a[i] = a[i - b[i] + b[i - 1]];

            val = max(val, a[i]);
        }
        else {
            a[i] = val + 1;
            val++;
        }
    }

    for (auto &it : a) {
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