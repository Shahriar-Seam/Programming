#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    string s, t;

    cin >> n >> s;

    for (i = 0; i < 2 * n - 1; i += 2) {
        t += s[i];
    }

    cout << t << "\n";
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