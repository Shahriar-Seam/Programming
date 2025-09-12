#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, cnt = 0;
    string s;

    cin >> n >> s;

    for (i = n - count(s.begin(), s.end(), '1') - 1; i >= 0; i--) {
        cnt += s[i] == '1';
    }

    cout << cnt << "\n";
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