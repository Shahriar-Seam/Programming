#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s, t, pre;
    int i, l;

    cin >> s >> t;

    l = min(s.size(), t.size());

    for (i = 0; i < l; i++) {
        if (s[i] == t[i]) {
            pre += s[i];
        }
        else {
            break;
        }
    }

    cout << pre.size() + (s.size() - pre.size()) + (t.size() - pre.size()) + (pre.size() > 0) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}