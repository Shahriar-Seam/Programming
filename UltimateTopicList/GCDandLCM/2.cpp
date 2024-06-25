#include <bits/stdc++.h>

using namespace std;

int _gcd(int a, int b)
{
    return b == 0 ? a : _gcd(b, a % b);
}

void solve()
{
    int a, b, g;

    cin >> a >> b;

    g = _gcd(a, b);

    cout << 1LL * a * b / g << " " << g << "\n";
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