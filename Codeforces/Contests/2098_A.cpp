#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    int i;
    multiset <char> ms;

    cin >> s;

    for (auto it : s) {
        ms.insert(it);
    }

    s = "";

    for (i = 9; i >= 0; i--) {
        auto it = ms.lower_bound(i + '0');

        s += *it;
        ms.erase(it);
    }

    for (auto it : ms) {
        s += it;
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