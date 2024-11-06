#include <bits/stdc++.h>

using namespace std;

/**
 * Author:  Ibnul Abrar Shahriar Seam
 * Date: 2024-11-06
 * License: CC0
 * Description: Count the number of divisors of a number
 * Time: O(sqrt(n))
**/

int count_divisor(int n)
{
    int divisor = 1, i, cnt;

    for (i = 0; primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            cnt = 1;

            while (n % primes[i] == 0) {
                n /= primes[i];
                cnt++;
            }

            divisor *= cnt;
        }
    }

    if (n > 1) {
        divisor *= 2;
    }

    return divisor;
}
