#include <bits/stdc++.h>

using namespace std;

const int sz = 1e3 + 50;
const int mod = 1073741824;
vector <bool> marked(sz, true);
vector <int> primes;

void sieve()
{
    int i, j;

    for (i = 3; i * i < sz; i += 2) {
        if (marked[i]) {
            for (j = i * i; j < sz; j += 2 * i) {
                marked[j] = false;
            }
        }
    }

    primes.push_back(2);

    for (i = 3; i < sz; i += 2) {
        if (marked[i]) {
            primes.push_back(i);
        }
    }
}

int count_divisor(int n)
{
    int divisor = 1, i, cnt;

    for (i = 0; primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            cnt = 1;

            while (n % primes[i] == 0) {
                n /= primes[i];
                cnt++;
            }

            divisor *= cnt;
        }
    }

    if (n > 1) {
        divisor *= 2;
    }

    return divisor;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int a, b, c, i, j, k, sum = 0;

    cin >> a >> b >> c;

    for (i = 1; i <= a; i++) {
        for (j = 1; j <= b; j++) {
            for (k = 1; k <= c; k++) {
                sum = (sum + count_divisor(i * j * k)) % mod;
            }
        }
    }

    cout << sum << "\n";

    return 0;
}