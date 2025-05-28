#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, cnt, ops = 0;
    string s;

    cin >> n >> s;

    vector <int> prefix_a(n + 1, 0), suffix_c(n + 1, 0);

    for (i = 0, cnt = 0; i < n; i++) {
        if (s[i] == 'A') {
            cnt++;
        }
        else if (s[i] == 'C') {
            cnt = 0;
        }

        prefix_a[i] = cnt;
    }

    for (i = n - 1, cnt = 0; i >= 0; i--) {
        if (s[i] == 'C') {
            cnt++;
        }
        else if (s[i] == 'A') {
            cnt = 0;
        }

        suffix_c[i] = cnt;
    }

    for (i = 0; i < n; i++) {
        if (s[i] == 'B') {
            ops += max(prefix_a[i], suffix_c[i]);
        }
    }

    cout << ops << "\n";
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