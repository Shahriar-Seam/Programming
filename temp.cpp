#include <bits/stdc++.h>

using namespace std;

vector <int> primes;

void sieve()
{
    int i, j, num = 50000;
    bool marked[num + 1];

    marked[0] = false;

    for (i = 3; i * i <= num; i += 2) {
        if (marked[i / 2] == true) {
            for (j = i * i; j <= num; j += i + i) {
                marked[j / 2] = false;
            }
        }
    }

    for (i = 1; i < num; i++) {
        if (marked[i]) {
            cout << 2 * i - 1 << " ";
        }
    }
}

void sieve(int n)
{
    bool is_prime[n + 1];
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            cout << i << " ";
        }
    }
}

int main()
{
    int i;

    sieve(100000);
    //sieve();

    for (i = 0; i < primes.size(); i++) {
        cout << primes[i] << " ";
    }

    return 0;
}