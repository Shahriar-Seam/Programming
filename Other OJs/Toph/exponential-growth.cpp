#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int bin_exp(int b, int p, int m = mod)
{
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * b) % m;
        }

        b = (b * b) % m;

        p >>= 1;
    }

    return result % m;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;

    cin >> x >> n;

    cout << bin_exp(x, n) << "\n";

    return 0;
}