#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, q;
    char x, y;
    string s;
    int ba = 0, bc = 0, ca = 0, cb = 0;

    cin >> n >> q >> s;

    for (i = 0; i < q; i++) {
        cin >> x >> y;

        ba += ({x, y} == {'b', 'a'});
        bc += ({x, y} == {'b', 'c'});
        ca += ({x, y} == {'c', 'a'});
        cb += ({x, y} == {'c', 'b'});
    }

    for (i = 0; i < n; i++) {
        if (s[i] == 'b') {
            if (ba > 0 || bc > 0 && )
        }
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