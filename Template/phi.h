#include <bits/stdc++.h>

using namespace std;

/**
 * Author:  Ibnul Abrar Shahriar Seam
 * Date: 2024-11-06
 * License: CC0
 * Description: Count the number of co primes smaller than n. Euler's totient function.
 * Time: O(sqrt(n))
**/

int phi(int n)
{
    int ret = n;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }

            ret -= ret / i;
        }
    }

    if (n > 1) {
        ret -= ret / n;
    }

    return ret;
}