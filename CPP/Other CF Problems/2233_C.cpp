#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, x;
    int l, r, c, i, o, mn_c = 1e9, mn_x = -1;
    string s;

    cin >> n >> k >> s;

    vector <int> v(n, 0);

    for (x = 0; x <= k; x++) {
        l = -1;
        r = n;

        for (i = 0, c = 0; c < x && i < n; i++) {
            if (s[i] == '(') {
                c++;
                l = i;
            }
        }

        for (i = n - 1, c = 0; c < k - x && i >= 0; i--) {
            if (s[i] == ')') {
                c++;
                r = i;
            }
        }

        l++;
        r--;

        for (i = l, c = 0, o = 0; i <= r; i++) {
            if (s[i] == '(') {
                o++;
            }
            else {
                if (o) {
                    o--;
                    c++;
                }
            }
        }

        if (c < mn_c) {
            mn_c = c;
            mn_x = x;
        }
    }

    for (i = 0, x = 0; x < mn_x && i < n; i++) {
        if (s[i] == '(') {
            v[i] = 1;

            x++;
        }
    }

    for (i = n - 1, x = 0; x < k - mn_x && i >= 0; i--) {
        if (s[i] == ')') {
            v[i] = 1;

            x++;
        }
    }

    for (auto &it : v) {
        cout << it;
    }

    cout << "\n";
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