#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, a, b;

    cin >> n >> a >> b;

    if (n & 1) {
        if (a > b) {
            if ((a & 1) && (b & 1)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            if (b & 1) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    else {
        if (a > b) {
            if ((a & 1) || (b & 1)) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
        else {
            if (b & 1) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
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