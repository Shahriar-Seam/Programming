#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, j, count = 0;
    string s;

    cin >> n >> k >> s;

    vector <int> marked(n, true);

    for (i = 0; i < n; i++) {
        if (s[i] == '1') {
            for (j = 0; j <= k && i + j < n; j++) {
                marked[i + j] = false;
            }
        }
    }

    cout << accumulate(marked.begin(), marked.end(), 0) << "\n";
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