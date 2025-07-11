#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    string s;

    cin >> n >> k >> s;

    if (k >= count(s.begin(), s.end(), '1')) {
        cout << "Alice\n";
    }
    else if (k > n / 2) {
        cout << "Alice\n";
    }
    else {
        cout << "Bob\n";
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