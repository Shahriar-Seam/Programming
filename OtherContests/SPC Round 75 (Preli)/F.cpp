#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;

    cin >> s;

    while (s.back() == '0') {
        s.pop_back();
    }

    cout << (count(s.begin(), s.end(), '0') ? "no" : "yes") << "\n";
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