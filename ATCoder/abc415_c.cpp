#include <bits/stdc++.h>

using namespace std;

bool possible(int n, string &s)
{
    int i;

    if (n == 0) {
        return true;
    }

    for (i = 0; i < (1 << n); i++) {
        if ((n & (1 << i)) && (s[n & ~(1 << i)] == '0')) {
            // cout << (n & ~(1 << i)) << " ";

            if (possible(n & ~(1 << i), s)) {
                return true;
            }
        }
    }

    return false;
}

void solve()
{
    int n, i, j;
    string s;

    cin >> n >> s;

    s.insert(s.begin(), '0');

    cout << (possible((1 << n) - 1, s) && s[(1 << n) - 1] == '0' ? "Yes" : "No") << "\n";
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