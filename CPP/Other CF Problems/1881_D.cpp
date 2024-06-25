#include <bits/stdc++.h>

using namespace std;

int max_size = 1000005;
vector <int> primes;
map <int, int> divisor_count;

void sieve()
{
    int i, j;

    primes.resize(max_size);

    for (i = 1; i < max_size; i += 2) {
        primes[i] = i;
        primes[i - 1] = 2;
    }

    primes[max_size - 1] = 2;

    for (i = 3; i * i < max_size; i += 2) {
        if (primes[i] == i) {
            for (j = i * i; j < max_size; j += i + i) {
                if (primes[j] == j) {
                    primes[j] = i;
                }
            }
        }
    }
}

void count_factors(int n)
{
    int p = primes[n];

    while (p != 1) {
        divisor_count[p]++;
        n /= p;
        p = primes[n];
    }
}

void solve()
{
    int n, i, temp, f = 1;

    divisor_count.clear();
    
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        count_factors(temp);
    }
    
    for (auto it : divisor_count) {
        if (it.second % n != 0) {
            f = 0;
        }
    }

    cout << (f ? "YES\n" : "NO\n");
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