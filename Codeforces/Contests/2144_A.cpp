#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, l, r, i, s1, s2, s3;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    l = 0;
    r = n - 1;

    for (l = 0; l < n; l++) {
        for (r = l + 1; r < n; r++) {
            s1 = s2 = s3 = 0;

            for (i = 0; i <= l; i++) {
                s1 += v[i];
            }

            for (i = l + 1; i < r; i++) {
                s2 += v[i];
            }

            for (i = r; i < n; i++) {
                s3 += v[i];
            }

            s1 %= 3;
            s2 %= 3;
            s3 %= 3;

            if (s1 == s2 && s2 == s3) {
                cout << l + 1 << " " << r + 1 << "\n";

                return;
            }
            else if (s1 != s2 && s2 != s3 && s1 != s3) {
                cout << l + 1 << " " << r + 1 << "\n";

                return;
            }
        }
    }

    cout << "0 0\n";
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