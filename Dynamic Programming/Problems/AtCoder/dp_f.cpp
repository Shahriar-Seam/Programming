#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t, p;
    int m, n, i, j;

    cin >> s >> t;

    n = s.size();
    m = t.size();

    vector <vector <int> > dp(n + 1, vector <int> (m + 1, 0));

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    i = n;
    j = m;

    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        }
        else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        }
        else {
            i--;
            j--;

            p += s[i];
        }
    }

    reverse(p.begin(), p.end());

    cout << p << "\n";

    return 0;
}