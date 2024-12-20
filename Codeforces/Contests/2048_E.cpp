#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, j;

    cin >> n >> m;

    if (2 * n <= m) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";

        for (i = 0; i < 2 * n; i++) {
            for (j = 1; j <= n; j++) {
                cout << j << " ";
            }

            cout << "\n";
        }
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