#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, first = 0, last = 0, f = 0;
    string s;

    cin >> n >> s;

    for (i = 0; i < n; i++) {
        if (!f && s[i] == 'B') {
            first = i;
            f = 1;
        }
        else if (f && s[i] == 'B') {
            last = i + 1;
        }
    }

    cout << max({last - first, (int) count(s.begin(), s.end(), 'B')}) << "\n";
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