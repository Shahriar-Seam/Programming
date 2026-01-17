#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    int i, count = 0, n;

    cin >> s;

    n = s.size();

    if (s[0] == 'u') {
        s[0] = 's';

        count++;
    }

    if (s[n - 1] == 'u') {
        s[n - 1] = 's';

        count++;
    }

    for (i = 1; i < n - 1; i++) {
        if (s[i - 1] == 'u' && s[i] != 's') {
            s[i] = 's';

            count++;
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