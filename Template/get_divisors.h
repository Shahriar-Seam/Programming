#include <bits/stdc++.h>

using namespace std;

/**
 * Author: Ibnul Abrar Shahriar Seam
 * Date: 2024-11-06
 * License: CC0
 * Description: Find all the divisors of n
 * Time: O(n log(n))
**/

#define sz int(1e6 + 5)
vector <vector <int> > divisors(sz, vector <int> ());

void get_divisors()
{
    int i, j;

    for (i = 1; i < sz; i++) {
        for (j = i; j < sz; j += i) {
            divisors[j].push_back(i);
        }
    }
}