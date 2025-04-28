#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    string ss;
    set <string> s;

    cin >> n;

    for (i = 1; i <= n; i++) {
        ss = to_string(i) + to_string(i + 1);

        sort(ss.begin(), ss.end());

        if (s.find(ss) != s.end()) {
            cout << i << " " << ss << "\n";
        }

        s.insert(ss);
    }

    cout << s.size() << "\n";
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