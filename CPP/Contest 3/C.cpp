#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k, *arr, i, sum = 0;

    cin >> n >> k;

    arr = new long long[n];

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (i = n - 1; i > n - k - 1; i--) {
        if (arr[i] < 0) {
            break;
        }
        sum += arr[i];
    }

    sum > 0 ? cout << sum : cout << 0;

    return 0;
}