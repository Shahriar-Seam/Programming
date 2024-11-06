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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    for (int i = 0; i < primes.size(); i += 500) {
        cout << primes[i] << '\n';
    }

    return 0;
}