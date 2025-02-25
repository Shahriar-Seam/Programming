#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x, mex = 0, i, o = 0;

    cin >> n >> x;

    vector <int> v(n);

    for (i = 0; i < 31; i++) {
        if (!(x & (1 << i))) {
            mex = 1 << i;

            break;
        }
    }

    for (i = 0; i < n; i++) {
        v[i] = i % mex;
    }

    for (i = 0; i < n; i++) {
        o |= v[i];
    }

    if (o != x) {
        v[n - 1] = x;
    }

    for (i = 0; i < n; i++) {
        cout << v[i] << " ";
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