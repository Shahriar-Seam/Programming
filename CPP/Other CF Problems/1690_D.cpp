#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, cnt = 0, max_count = 0;
    string s;

    cin >> n >> k >> s;

    vector <int> v(n, 0);

    for (i = 0; i < n; i++) {
        if (s[i] == 'W') {
            v[i] = 1;
        }
    }

    for (i = 0; i < k; i++) {
        cnt += v[i];
    }

    max_count = cnt;

    for (i; i < n; i++) {
        cnt += v[i];
        cnt -= v[i - k];

        max_count = min(max_count, cnt);
    }

    cout << max_count << "\n";
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