#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, count = 0, i;
    int p = 0;
    string s;

    cin >> n >> s;

    for (i = 0; i < n; i++) {
        if (!p && s[i] == '1') {
            count++;

            p = 1;
        }
        else if (p && s[i] == '0') {
            count++;

            p = 0;
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