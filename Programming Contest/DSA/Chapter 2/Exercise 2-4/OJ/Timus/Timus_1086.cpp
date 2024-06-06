#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

void sieve() 
{
    int size = 200000;
    int i, p;
    vector<int> isPrime(size + 1, true);

    for (p = 2; p * p <= size; p++) { 
        if (isPrime[p]) { 
            for (i = p * p; i <= size; i += p) {
                isPrime[i] = false;
            }
        } 
    }

    for (i = 2; i <= size; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;

    sieve();

    cin >> t;

    while (t--) {
        cin >> n;

        cout << primes[n - 1] << "\n";
    }

    return 0;
}
