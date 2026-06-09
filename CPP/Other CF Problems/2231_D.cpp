#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, b = 0, mx = -1e18, last = -1;
    string s;

    cin >> n >> s;

    vector <int> a(n), c(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : c) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (s[i] == '1') {
            b += a[i];
            mx = max(mx, b);

            if (mx != c[i]) {
                if (last >= 0) {
                    a[last] = c[i] - b;
                    b += a[last];
                    last = -1;
                    mx = c[i];
                }
                else {
                    cout << "NO\n";

                    return;
                }
            }
        }
        else {
            if (mx != c[i]) {
                a[i] = c[i] - b;
                b += a[i];
                last = -1;
            }
            else if (mx == c[i]) {
                last = i;
            }
        }

        mx = max(mx, b);
    }

    for (i = 0, b = 0, mx = -1e18; i < n; i++) {
        b += a[i];

        mx = max(mx, b);

        if (mx != c[i]) {
            cout << "NO\n";

            return;
        }
    }

    cout << "YES\n";

    for (auto &it : a) {
        cout << it << " ";
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