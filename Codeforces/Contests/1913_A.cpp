#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;

    cin >> s;

    int len = s.size();
    int f = 1;

    for (int i = 1; i < len; i++) {
        if (s[i] != '0') {
            f = i;
            break;
        }
    }

    string s1, s2;

    for (int i = 0; i < f; i++) {
        s1.push_back(s[i]);
    }
    for (int i = f; i < len; i++) {
        s2.push_back(s[i]);
    }

    if (stoi(s1) < stoi(s2)) {
        cout << s1 << " " << s2 << "\n";
    }
    else {
        cout << "-1\n";
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