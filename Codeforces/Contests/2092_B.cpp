#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    string s, t;
    int odd_s = 0, even_s = 0, odd_t = 0, even_t = 0;

    cin >> n >> s >> t;

    for (i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (i % 2 == 0) {
                even_s++;
            }
            else {
                odd_s++;
            }
        }

        if (t[i] == '0') {
            if (i % 2 == 0) {
                even_t++;
            }
            else {
                odd_t++;
            }
        }
    }

    if (even_t >= odd_s && odd_t >= even_s) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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