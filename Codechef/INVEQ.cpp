#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, cnt = 0, i;
    string s;

    cin >> n >> s;

    for (i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            cnt++;
        }
    }

    if ((count(s.begin(), s.end(), '1') == 0) || (count(s.begin(), s.end(), '0') == 0)) {
        cout << 0 << "\n";
    }
    else {
        cout << (cnt + 1) / 2 << "\n";
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