#include <bits/stdc++.h>

using namespace std;

#define sz int(1e9 + 5)
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


void solve()
{
    int n;

    cin >> n;

    cout << count_divisor(n) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}