#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int l, r, i, count = 0;

    cin >> l >> r;

    for (i = l; i <= r; i++) {
        count += !(i % 2);
    }

    cout << count << "\n";
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