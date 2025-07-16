#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    string s;

    cin >> n >> s;

    if ((count(s.begin(), s.end(), '0') % 2) == 0) {
        cout << "BOB\n";
    }
    else {
        if (count(s.begin(), s.end(), '0') == 1) {
            cout << "BOB\n";
        }
        else {
            cout << "ALICE\n";
        }
    }
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