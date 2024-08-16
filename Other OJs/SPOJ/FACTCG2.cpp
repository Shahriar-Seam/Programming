#include <bits/stdc++.h>

using namespace std;

#define max_size 3200
vector <int> primes;
vector <int> divisors;

void sieve()
{
    int i, j;
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

void get_divisors(int n)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j = 0;

    divisors.clear();
    
    while (j < primes.size() && primes[j] * primes[j] <= n) {
        while (n % primes[j] == 0) {
            divisors.push_back(primes[j]);

            n /= primes[j];
        }

        j++;
    }

    if (n > 1) {
        divisors.push_back(n);
    }
}

void print_divisors()
{
    int i;

    cout << 1;

    for (i = 0; i < divisors.size(); i++) {
        cout << " x " << divisors[i];
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n;

    while (scanf("%d", &n) != EOF) {
        divisors.clear();

        get_divisors(n);

        print_divisors();
    }

    return 0;
}