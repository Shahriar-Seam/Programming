#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long l, r, i, j;

    cin >> l >> r;

    for (i = l, j = 1; i <= r; i += j, j++);

    cout << j - 1 << "\n";
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