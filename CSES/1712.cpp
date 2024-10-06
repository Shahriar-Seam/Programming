#include <bits/stdc++.h>

using namespace std;

long long binary_exponentiation(long long b, long long p, long long mod)
{
    long long result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * b) % mod;
        }

        b = (b * b) % mod;

        p >>= 1;
    }

    return result;
}

void solve()
{
    long long a, b, c;

    cin >> a >> b >> c;

    cout << binary_exponentiation(a, binary_exponentiation(b, c, int(1e9 + 6)), int(1e9 + 7)) << "\n";
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