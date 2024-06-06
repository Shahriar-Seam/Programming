#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, *arr, i, f = 0;

    cin >> n;

    arr = new int[n];

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (i = 0; i < n - 2; i++) {
        if (arr[i] + arr[i + 1] > arr[i + 2]) {
            f = 1;
            break;
        }
    }

    f ? cout << "YES\n" : cout << "NO\n";

    delete[] arr;

    return 0;
}