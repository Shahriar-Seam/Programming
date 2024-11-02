#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long l, r, i, k, j;

    cin >> l >> r >> i >> k;

    i = (1 << i);

    for (j = 1; j < l; j++) {
        if (j % i == k) {
            cout << j << " ";
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