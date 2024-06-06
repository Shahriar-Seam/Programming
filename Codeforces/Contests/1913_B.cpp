#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s, t;
    int z = 0, o = 0, i, len, cnt = 0;

    cin >> s;

    len = s.size();
    
    for (i = 0; i < len; i++) {
        if (s[i] == '0') {
            z++;
        }
        else {
            o++;
        }
    }

    for (i = 0; i < len; i++) {
        if (z > 0 && s[i] == '1') {
            t.push_back('0');
            z--;
        }
        else if (o > 0 && s[i] == '0') {
            t.push_back('1');
            o--;
        }
        else {
            t.push_back(s[i]);
        }
    }

    cout << s << " " << t << "\n";

    for (i = 0; i < len; i++) {
        if (s[i] == t[i]) {
            cnt++;
        }
    }

    cout << cnt << "\n";
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