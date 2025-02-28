#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, k, i, j, count = 0, zeros = 0;
    string s;

    cin >> n >> m >> k >> s;

    for (i = 0; i < n; i++) {
        if (s[i] == '1') {
            zeros = 0;
        }
        else {
            zeros++;

            if (zeros == m) {
                for (j = i; j < i + k && j < n; j++) {
                    s[j] = '1';
                }

                count++;

                zeros = 0;

                i += k - 1;
            }
        }
    }

    cout << count << "\n";
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