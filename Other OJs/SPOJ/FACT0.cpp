#include <bits/stdc++.h>

using namespace std;

#define max_size 32000000
vector <long long> primes;
map <long long, int> divisors;

void sieve()
{
    long long i, j;
    vector <bool> marked(max_size + 1, true);

    marked[0] = false;

    for (i = 3; i * i <= 2 * max_size; i += 2) {
        if (marked[i / 2] == true) {
            for (j = i * i; j <= 2 * max_size; j += (2 * i)) {
                marked[j / 2] = false;
            }
        }
    }

    primes.push_back(2);

    for (i = 1; i < max_size; i++) {
        if (marked[i] == true) {
            primes.push_back(2 * i + 1);
        }
    }
}

void get_divisors(long long n)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long i, j = 0;
    
    while (j < primes.size() && primes[j] * primes[j] <= n) {
        while (n % primes[j] == 0) {
            divisors[primes[j]]++;

            n /= primes[j];
        }

        j++;
    }

    if (n > 1) {
        divisors[n]++;
    }
}

void print_divisors()
{
    for (auto it : divisors) {
        cout << it.first << "^" << it.second << " ";
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    long long n;

    while (1) {
        cin >> n;

        if (n == 0) {
            break;
        }

        divisors.clear();

        get_divisors(n);

        print_divisors();
    }

    return 0;
}