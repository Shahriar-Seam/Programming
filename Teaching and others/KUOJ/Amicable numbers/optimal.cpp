#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 3200;
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

int sum_of_divisors(int num)
{
    int total = 1, sum, pow, i;

    for (auto it : primes) {
        if (it * it > num) {
            break;
        }

        if (num % it == 0) {
            int e = 0;

            do {
                e++;

                num /= it;
            } while (num % it == 0);

            sum = 0, pow = 1;

            do {
                sum += pow;
                pow *= it;
            } while (e-- > 0);

            total *= sum;
        }
    }

    if (num > 1) {
        total *= (1 + num);
    }

    return total;
}

void solve()
{
    int n, m;

    cin >> n;

    m = sum_of_divisors(n) - n;
    
    if (n > 1 && m != n && sum_of_divisors(m) - m == n) {
        cout << m << "\n";
    }
    else {
        cout << "-1" << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}