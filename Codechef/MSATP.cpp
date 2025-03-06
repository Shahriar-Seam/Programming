#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    string s, t;
    vector <int> counter(3, 0);

    cin >> n >> s >> t;

    for (i = 0; i < n; i++) {
        counter[s[i] - '0' + t[i] - '0']++;
    }

    cout << ((counter[0] % 2 + counter[1] % 2 + counter[2] % 2) <= 1 ? "YES" : "NO") << "\n";
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