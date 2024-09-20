#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x, y;

    cin >> n >> x >> y;

    cout << ceil(n / (1.0 * min(x, y))) << "\n";
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