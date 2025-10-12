#include <bits/stdc++.h>

using namespace std;

string str(int n)
{
    string s = to_string(n);

    if (n < 10) {
        s = '0' + s;
    }

    return s;
}

void solve()
{
    string s;
    int h, m;

    cin >> s;

    h = stoi(s.substr(0, 2));
    m = stoi(s.substr(3, 2));

    while ((str(h) != str(m)) || (str(h)[0] != str(h)[1])) {
        m++;

        if (m >= 60) {
            h++;
            m %= 60;
        }

        if (h >= 24) {
            h %= 24;
        }
    }

    cout << str(h) << ":" << str(m) << "\n";
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