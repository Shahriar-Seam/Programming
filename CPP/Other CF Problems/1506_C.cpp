#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string a, b;
    int n, m, i, j, k, length = 0, len = 0;

    cin >> a >> b;

    n = a.size();
    m = b.size();

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                len = 0;

                for (k = 0; i + k < n && j + k < m; k++) {
                    if (a[i + k] == b[j + k]) {
                        len++;
                    }
                    else {
                        break;
                    }
                }

                length = max(length, len);
            }
        }
    }

    cout << n + m - 2 * length << "\n";
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