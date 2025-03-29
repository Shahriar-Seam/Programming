#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, r, b, i, p, q;

    cin >> n >> r >> b;

    p = r / (b + 1);
    q = r % (b + 1);

    for (i = 0; i < q; i++) {
        cout << string(p + 1, 'R') << "B";
    }

    for (i = q; i < b; i++) {
        cout << string(p, 'R') << "B";
    }

    cout << string(p, 'R') << "\n";
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