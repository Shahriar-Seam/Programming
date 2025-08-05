#include <bits/stdc++.h>

using namespace std;

bool possible(string &s, int n, int m, int k)
{
    int i, zero = 0, len = 0, count = 0;

    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            zero++;
        }
        else {
            len++;
        }

        len = max(len, zero);
        
        if (len >= m) {
            zero = 0;
            len = 0;

            count++;
        }
    }

    return count >= k;
}

void solve()
{
    int n, k, i;
    string s;
    int l, r, m, val = 1;

    cin >> n >> k >> s;

    l = 1;
    r = n;

    while (l <= r) {
        m = (l + r) / 2;

        if (possible(s, n, m, k)) {
            val = m;

            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    cout << val << "\n";
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