#include <bits/stdc++.h>

using namespace std;

#define mod int(1e9 + 7)

void solve()
{
    long long a, b, p = 1;

    cin >> a >> b;

    if (b == 0) {
        cout << 1 << "\n";

        return;
    }

    while (b > 0) {
        if (b & 1) {
            p = (p * a) % mod;
        }

        a = (a * a) % mod;

        b >>= 1;
    }

    cout << p << "\n";
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