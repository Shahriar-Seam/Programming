#include <bits/stdc++.h>

using namespace std;

/**
 * Author:  Ibnul Abrar Shahriar Seam
 * Date: 2024-11-06
 * License: CC0
 * Description: Find all the prime factors of n
 * Time: O(sqrt(n))
**/

vector <int> get_factors(int n)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j = 0;
    vector <int> factors;
    
    while (j < primes.size() && primes[j] * primes[j] <= n) {
        while (n % primes[j] == 0) {
            factors.push_back(primes[j]);

            n /= primes[j];
        }

        j++;
    }

    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}
