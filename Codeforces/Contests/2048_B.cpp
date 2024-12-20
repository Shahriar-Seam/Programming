#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, j, l;

    cin >> n >> k;

    if (k == 1) {
        for (i = 1; i <= n; i++) {
            cout << i << " ";
        }
    }
    else {
        for (i = n, l = 1, j = 1; l <= n; l++) {
            if (l % k == 0) {
                cout << j++ << " ";
            }
            else {
                cout << i-- << " ";
            }
        }
    }

    cout << "\n";
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