#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int f = 1, i;
    string s;

    cin >> s;

    if (s[0] != '1' || s.back() == '9') {
        f = 0;
    }
    else {
        for (i = 1; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                f = 0;

                break;
            }
        }
    }

    cout << (f == 1 ? "YES" : "NO") << "\n";
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