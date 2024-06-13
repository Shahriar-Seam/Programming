#include <bits/stdc++.h>

using namespace std;

vector <int> primes;
int max_size = 500000;

void sieve()
{
    int i, j;
    bool marked[max_size] = {};

    marked[0] = marked[1] = true;

    for (i = 3; i * i <= max_size; i += 2) {
        if (marked[i] == false) {
            for (j = i * i; j <= max_size; j += i + i) {
                marked[j] = true;
            }
        }
    }

    for (i = 3; i < max_size; i += 2) {
        if (marked[i] == false) {
            primes.push_back(i);
        }
    }
}

bool is_square(long long n)
{
    return ceil(sqrt(n)) == floor(sqrt(n));
}

void solve()
{
    int i, f = 0;
    long long n;

    cin >> n;

    n -= 4;

    for (i = 0; i < n; i++) {
        if (n < primes[i] * primes[i]) {
            break;
        }
        else if (is_square(n - 1LL * primes[i] * primes[i])) {
            if (binary_search(primes.begin(), primes.end(), sqrt(n - 1LL * primes[i] * primes[i])) == true) {
                if (n - 1LL * primes[i] * primes[i] != 1LL * primes[i] * primes[i]) {
                    f = 1;

                    break;
                }
            }
        }
    }

    cout << (f == 1 ? "YES\n" : "NO\n");
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