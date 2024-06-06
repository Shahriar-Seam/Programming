#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, l, i, j;

    cin >> n >> l;

    if (l > 1000000) {
        for (i = 1, j = 0; j < n; j++, i++) {
            cout << i << " ";
        }
    }
    else {
        for (i = l + l, j = 0; j < n; j++, i += l + 1) {
            cout << i << " ";
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