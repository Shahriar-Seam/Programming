#include <bits/stdc++.h>

using namespace std;

int ceil_div(int a, int b)
{
    return (a + b - 1) / b;
}

void solve()
{
    int n, l, r, i, start = 0;

    cin >> n >> l >> r;

    vector <int> v;

    for (i = 1; i <= n; i++) {
        v.push_back(ceil_div(l, i) * i);
    }

    if (*max_element(v.begin(), v.end()) > r) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";

        for (i = 0; i < n; i++) {
            cout << v[i] << " ";
        }

        cout << "\n";
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