#include <bits/stdc++.h>

using namespace std;

bool check(string s, string t)
{
    int i;

    for (i = 0; i < s.size(); i++) {
        if (s[i] == t[i] || t[i] == '?') {
            continue;
        }
        else {
            return false;
        }
    }

    return true;
}

bool valid(string t, string u)
{
    string s;
    int i, j;

    for (i = 0; i < t.size() - u.size() + 1; i++) {
        s = t;

        for (j = 0; j < u.size(); j++) {
            s[i + j] = u[j];
        }

        if (check(s, t)) {
            return true;
        }
    }

    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string t, u;

    cin >> t >> u;

    cout << (valid(t, u) ? "Yes\n" : "No\n");

    return 0;
}