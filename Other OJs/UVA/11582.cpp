#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > fib(1001);

void cycle()
{
    int i, j;

    fib[0].push_back(0);
    fib[1].push_back(0);

    for (i = 2; i <= 1000; i++) {
        fib[i].push_back(0);
        fib[i].push_back(1);

        for (j = 2; ; j++) {
            fib[i].push_back((fib[i][j - 1] + fib[i][j - 2]) % i);

            if (fib[i][j - 1] == fib[i][0] && fib[i][j] == fib[i][1]) {
                fib[i].pop_back();
                fib[i].pop_back();

                break;
            }
        }
    }
}

int binary_exponentiation(unsigned long long b, unsigned long long p, unsigned long long mod)
{
    __int128_t result = 1;

    while (p > 0) {
        if (p & 1LLU) {
            result = (result * b) % mod;
        }

        b = (b * b) % mod;

        p >>= 1ULL;
    }

    return (int) (result % mod);
}

void solve()
{
    unsigned long long a, b, n, len, ab;

    cin >> a >> b >> n;

    len = fib[n].size();

    ab = binary_exponentiation(a % len, b, len);

    cout << fib[n][ab] << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cycle();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}