#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int i;
    string s;

    cin >> s;

    for (i = 0; i < s.size(); i++) {
        if (s[i] == 'p') {
            s[i] = 'q';
        }
        else if (s[i] == 'q') {
            s[i] = 'p';
        }
    }

    reverse(s.begin(), s.end());

    cout << s << "\n";
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