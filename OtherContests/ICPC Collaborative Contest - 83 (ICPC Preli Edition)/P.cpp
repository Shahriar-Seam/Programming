#include <bits/stdc++.h>

using namespace std;

#define mod int(1e9 + 7)

long long binex(long long b, long long p)
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

long long sum(long long a, long long r, long long n)
{
    return (a * (binex(r, n) - 1) / (r - 1)) % mod;
}

void solve()
{
    long long a, b, c, d;

    cin >> a >> b >> c >> d;

    // 1st row sum
    long long sum1 = sum((binex(2, a) * binex(3, c)) % mod, 3, d - c + 1);

    // 2*3
    long long sum2 = sum(sum1, 2, b - a + 1);

    cout << sum2 << "\n";
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