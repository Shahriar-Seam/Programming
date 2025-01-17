#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, x, y, ans = 0;

    cin >> n >> m;

    ans = m + m;

    for (i = 0; i < n; i++) {
        cin >> x >> y;
        
        if (i > 0) {
            ans += x + y;
        }
    }

    cout << 2 * ans << "\n";
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