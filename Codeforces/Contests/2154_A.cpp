#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, last = -1, count = 0;
    string s;

    cin >> n >> k >> s;

    for (i = 0; i < n; i++) {
        if (last == -1 && s[i] == '1') {
            last = i;

            count++;
        }
        else if (s[i] == '1') {
            int f = 0;

            for (int j = max(0, i - k + 1); j < i; j++) {
                if (s[j] == '1') {
                    f = 1;
                }
            }

            if (!f) {
                last = i;

                count++;
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