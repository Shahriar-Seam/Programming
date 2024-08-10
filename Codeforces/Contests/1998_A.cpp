#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int xc, yc, k, i, j;

    cin >> xc >> yc >> k;

    if (k & 1) {
        for (i = xc, j = yc; i <= xc + (k / 2); i++, j++) {
            cout << i << " " << j << "\n";
        }

        for (i = xc - 1, j = yc - 1; i >= xc - (k / 2); i--, j--) {
            cout << i << " " << j << "\n";
        }
    }
    else {
        for (i = xc + 1, j = yc + 1; i <= xc + (k / 2); i++, j++) {
            cout << i << " " << j << "\n";
        }

        for (i = xc - 1, j = yc - 1; i >= xc - (k / 2); i--, j--) {
            cout << i << " " << j << "\n";
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