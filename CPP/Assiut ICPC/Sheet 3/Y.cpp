#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, q, *arr, i, l, r, sum;

    cin >> n >> q;

    arr = new long long[n]();

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (q--) {
        cin >> l >> r;

        sum = 0;
        l--;

        sum = accumulate(arr + l, arr + r, sum);

        cout << sum << "\n";
    }

    delete[] arr;

    return 0;
}