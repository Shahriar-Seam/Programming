#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, count = 0;
    int bleh = 0;
    char c;
    string s;

    cin >> n >> c >> s;

    for (i = 0; i < n; i++) {
        if (s[i] != c) {
            count++;
        }
        else {
            bleh = i + 1;
        }
    }

    if (count == 0) {
        cout << 0 << "\n";
    }
    else if (2 * bleh > n) {
        cout << 1 << "\n" << bleh << "\n";
    }
    else if (s[n - 1] == c) {
        cout << 1 << "\n" << n << "\n";
    }
    else {
        cout << "2\n" << n - 1 << " " << n << "\n";
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