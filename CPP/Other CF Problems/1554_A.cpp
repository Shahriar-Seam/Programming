#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, i;
    long long *arr, product;

    cin >> t;

    while (t--) {
        cin >> n;

        arr = new long long[n];
        product = 0;

        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for (i = 0; i < n - 1; i++) {
            product = max({product, arr[i] * arr[i + 1]});
        }

        cout << product << "\n";

        delete[] arr;
    }

    return 0;
}