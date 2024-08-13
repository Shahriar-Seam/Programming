#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int flag = 1;
    string s;

    cin >> s;

    if (s.size() <= 2) {
        cout << "NO\n";

        return;
    }

    if (s.size() <= 3) {
        if (s[2] == '1') {
            flag = 0;
        }

        s += '0';
    }

    string f = s.substr(0, 2);
    string l = s.substr(2, 2);

    if (flag == 1 && f == "10" && stoi(l) >= 10) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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