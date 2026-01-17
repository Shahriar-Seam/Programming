#include <bits/stdc++.h>

using namespace std;

#define int long long

int bin_exp(int b, int p, int m = 1000)
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

string pad(int n)
{
    string s = to_string(n);

    while (s.size() < 3) {
        s = '0' + s;
    }

    return s;
}

int initial(int n, int k)
{
    double l = k * log10(n);

    l = l - (long long) l;

    double result = pow(10, l);

    while (result > 1000) {
        result /= 10;
    }

    while (result < 100) {
        result *= 10;
    }

    return result;
}

void solve()
{
    int n, k;

    cin >> n >> k;

    cout << initial(n, k) << "..." << pad(bin_exp(n, k)) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}