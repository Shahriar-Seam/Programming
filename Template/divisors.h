#include <bits/stdc++.h>

using namespace std;

/**
 * Author:  Ibnul Abrar Shahriar Seam
 * Date: 2024-11-06
 * License: CC0
 * Description: Count the number of divisors of a number. Doesn't need sieve to precalculate primes.
 * Time: O(n log n)
**/

const int sz = 1e6 + 5;
int divisors[sz] = {};

void fill_divisors()
{
    int i, j;

    for (i = 1; i < sz; i++) {
        for (j = i; j < sz; j += i) {
            divisors[j]++;
        }
    }
}