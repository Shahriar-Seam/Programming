#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    int i;

    cin >> s;

    reverse(s.begin(), s.end());

    for (i = 0; i < s.size(); i++) {
        if (s[i] == 'L') {
            s[i] = 'R';
        }
        else if (s[i] == 'R') {
            s[i] = 'L';
        }
    }

    cout << s << "\n";
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