#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int m, a, b, c;
    int total = 0;

    cin >> m >> a >> b >> c;

    total = min(a, m) + min(b, m);

    total = min(2 * m, total + c);

    cout << total << "\n";
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