#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e7 + 7;

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

    int n, k;

    while (true) {
        cin >> n >> k;

        if (n == 0 && k == 0) {
            break;
        }

        cout << (2 * bin_exp(n - 1, k) + bin_exp(n, k) + 2 * bin_exp(n - 1, n - 1) + bin_exp(n, n)) % mod << "\n";
    }

    return 0;
}