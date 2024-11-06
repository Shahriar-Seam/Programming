#include <bits/stdc++.h>

using namespace std;

/**
 * Author:  Ibnul Abrar Shahriar Seam
 * Date: 2024-11-07
 * License: CC0
 * Description: Calculate the sum of proper divisors of a number. Needs sieve and prime factorization
 * Time: O(sqrt(n) / log(n) + k)
**/

int sum_of_divisors(int n)
{
    long long sum = 1, temp;

    map <int, int> factors = get_factors(n);

    for (auto it : factors) {
        temp = 1;

        while (it.second > 0) {
            temp += binary_exponentiation(it.first, it.second);

            it.second--;
        }

        sum *= temp;
    }

    sum -= n;

    return sum;
}