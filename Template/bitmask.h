#include <bits/stdc++.h>

using namespace std;

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