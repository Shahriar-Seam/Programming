#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    string s;

    cin >> n >> s;

    s += "))))";

    for (i = 0; i < n; i++) {
        if (s[i] == '(' && s[i + 1] == ')') {
            if (s[i + 2] == '(' && s[i + 3] == '(') {
                cout << n - 2 << "\n";

                return;
            }
        }
    }

    cout << "-1\n";
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