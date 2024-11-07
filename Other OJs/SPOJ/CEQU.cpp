#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, c;

    cin >> a >> b >> c;

    cout << (c % __gcd(a, b) == 0 ? "Yes" : "No") << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}