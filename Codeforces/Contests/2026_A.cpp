#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, y, k;

    cin >> x >> y >> k;

    cout << 0 << " " << min(x, y) << " " << min(x, y) << " 0" << "\n";
    cout << min(x, y) << " " << min(x, y) << " 0 0" << "\n";
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