#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, zeroes = 0, cnt, l = -1, r = -1;
    string s;
    vector <int> ones;

    cin >> n >> s;

    if (count(s.begin(), s.end(), '0') == 0 || count(s.begin(), s.end(), '1') == 0) {
        cout << 0 << "\n";

        return;
    }

    for (i = 0; i < n; i++) {
        
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