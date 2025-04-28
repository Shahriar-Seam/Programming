#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    string s;

    cin >> n >> s;

    if (s == "AB") {
        cout << "Alice\n";
    }
    else if (s == "BA") {
        cout << "Bob\n";
    }
    else if (s[0] == 'A' && s[n - 1] == 'A') {
        cout << "Alice\n";
    }
    else if (s[0] == 'B' && s[n - 1] == 'B') {
        cout << "Bob\n";
    }
    else if (s[0] == 'A' && s[n - 1] == 'B' && count(s.begin(), s.end(), 'B') > 1) {
        cout << "Bob\n";
    }
    else if (s[0] == 'A' && s[n - 1] == 'B' && count(s.begin(), s.end(), 'B') == 1) {
        cout << "Alice\n";
    }
    else if (s[0] == 'B' && s[n - 1] == 'A' && s[n - 2] == 'A') {
        cout << "Alice\n";
    }
    else if (s[0] == 'B' && s[n - 1] == 'A' && s[n - 2] == 'B') {
        cout << "Bob\n";
    }
    else {
        cout << "Bleh\n";
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