#include <bits/stdc++.h>

using namespace std;

/**
 * Author:  Ibnul Abrar Shahriar Seam
 * Date: 2024-11-06
 * License: CC0
 * Description: Binary exponentiation with mod
 * Time: O(log n)
**/

#define mod int(1e9 + 7)

long long binary_exponentiation(long long b, long long p)
{
    long long result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * b) % mod;
        }

        b = (b * b) % mod;

        p >>= 1;
    }

    return result;
}