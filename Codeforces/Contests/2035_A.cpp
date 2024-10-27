#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, m, r, c;

    cin >> n >> m >> r >> c;

    long long total = (n - r) * m + m - c;

    cout << total + (n - r) * (m - 1) << "\n";
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