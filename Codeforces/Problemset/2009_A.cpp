#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, c, m = 51651654;

    cin >> a >> b;

    for (int i = a; i <= b; i++) {
        m = min(m, (c - a) + (b - c));
    }

    cout << m << "\n";
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