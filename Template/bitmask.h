#include <bits/stdc++.h>

using namespace std;

/**
 * Author:  Ibnul Abrar Shahriar Seam
 * Date: 2024-11-06
 * License: CC0
 * Description: Sum of all subsets
 * Time: O(n * 2 ^ n)
**/

void bitmask(int *arr, int n)
{
    int i, mask, sum = 0;

    for (mask = 0; mask < (1 << n); mask++) {
        sum = 0;

        for (i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }

        cout << sum << "\n";
    }
}