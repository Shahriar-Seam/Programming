#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;

    cin >> s;

    sort(s.begin(), s.end(), greater <> ());

    cout << s << "\n";
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