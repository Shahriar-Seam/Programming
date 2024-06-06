#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, *arr, i, cnt = 0;

    cin >> n;

    arr = new int[n];

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (i = 0; i < n; i++) {
        if (binary_search(arr + i, arr + n, arr[i] + 1) == true) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}