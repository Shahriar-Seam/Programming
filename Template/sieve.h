#include <bits/stdc++.h>

using namespace std;

/**
 * Author:  Ibnul Abrar Shahriar Seam
 * Date: 2024-11-06
 * License: CC0
 * Description: Sieve of eratosthenes. Finds and stores primes upto sz
 * Time: O(n log log n)
**/

#define sz int(1e6 + 5)
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
