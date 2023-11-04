#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, t, l, r, i;
    long long *arr, *arr2, sum;

    cin >> n;

    arr = new long long[n];
    arr2 = new long long[n]();

    for (i = 0; i < n; i++) {
        cin >> arr[i];

        arr2[i] = arr[i];
    }

    sort(arr2, arr2 + n);

    cin >> m;

    while (m--) {
        cin >> t >> l >> r;

        sum = 0;

        if (t == 1) {
            for (i = l - 1; i < r; i++) {
                sum += arr[i];
            }
        }
        else {
            for (i = l - 1; i < r; i++) {
                sum += arr2[i];
            }
        }

        cout << sum << "\n";
    }

    return 0;
}