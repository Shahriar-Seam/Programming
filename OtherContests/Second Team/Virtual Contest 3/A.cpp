#include <bits/stdc++.h>

using namespace std;

bool same(string &s, string &t)
{
    int i;

    for (i = 0; i <= s.size(); i++) {
        if (s == t) {
            return true;
        }

        s = s[s.size() - 1] + s;

        s.pop_back();
    }

    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;

    cin >> s >> t;

    cout << (same(s, t) ? "Yes" : "No") << "\n";

    return 0;
}