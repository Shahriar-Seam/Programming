#include <bits/stdc++.h>

using namespace std;

int max_size = 1000005;
vector <long long> primes;
map <long long, long long> factors;

void sieve()
{
    int i, j;
    vector <bool> marked(max_size, true);

    for (i = 3; i * i < max_size; i += 2) {
        if (marked[i] == true) {
            for (j = i * i; j < max_size; j += i + i) {
                marked[j] = false;
            }
        }
    }

    primes.push_back(2);

    for (i = 3; i < max_size; i += 2) {
        if (marked[i] == true) {
            primes.push_back(i);
        }
    }
}

void count_factors(long long n)
{
    int i;

    for (i = 0; i < primes.size() && 1LL * primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            while (n % primes[i] == 0) {
                factors[primes[i]]++;

                n /= primes[i];
            }
        }
    }

    if (n > 1) {
        factors[n]++;
    }
}

long long binary_exponentiation(long long b, long long p)
{
    long long result = 1;

    while (p > 0) {
        if (p & 1) {
            result = result * b;
        }

        b = b * b;

        p >>= 1;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    long long n, mask, i, div1, div2, min_div = LONG_LONG_MAX;
    long long len;
    pair <long long, long long> p;

    cin >> n;

    count_factors(n);

    vector <pair <long long, long long> > v(begin(factors), end(factors));

    len = v.size();

    for (mask = 0; mask <= (1 << len); mask++) {
        div1 = div2 = 1;

        for (i = 0; i < len; i++) {
            if (mask & (1 << i)) {
                div1 *= binary_exponentiation(v[i].first, v[i].second);
            }
            else {
                div2 *= binary_exponentiation(v[i].first, v[i].second);
            }
        }

        if (max(div1, div2) < min_div) {
            min_div = max(div1, div2);
            p = make_pair(div1, div2);
        }
    }

    cout << p.first << " " << p.second;

    return 0;
}