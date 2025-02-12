#include <bits/stdc++.h>

using namespace std;

const int sz = 1e6 + 5;
vector <bool> marked(sz, true);
vector <int> primes;
vector <int> divisors(sz, 0);
vector <int> factors(sz, 0);
vector <int> final_arr;

int _log(int n, int b)
{
    int count = 0;

    while (n % b == 0) {
        n /= b;

        count++;
    }

    return count;
}

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

void fill_divisors()
{
    int i, j;

    for (i = 1; i < sz; i++) {
        for (j = i; j < sz; j += i) {
            divisors[j]++;
        }
    }
}

void fill_factors()
{
    int i, j, temp;

    for (i = 0; primes[i] * primes[i] < sz; i++) {
        for (j = primes[i]; j < sz; j += primes[i]) {
            temp = _log(j, primes[i]);

            if (temp == 1) {
                factors[j]++;
            }
            else {
                factors[j] += 50;
            }
        }
    }
}

void fill_again()
{
    int i;

    for (i = 1; i < sz; i++) {
        if (factors[divisors[i]] == 2) {
            final_arr.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    fill_divisors();
    fill_factors();
    fill_again();

    int i;

    for (i = 8; i < final_arr.size(); i += 9) {
        cout << final_arr[i] << "\n";
    }

    return 0;
}