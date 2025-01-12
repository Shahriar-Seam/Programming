#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, a, b;

    cin >> n >> a >> b;

    cout << ((abs(a - b) % 2) == 1 ? "NO" : "YES") << "\n";
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