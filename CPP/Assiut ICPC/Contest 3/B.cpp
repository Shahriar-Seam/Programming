#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, *arr, i;

    cin >> n;

    arr = new int[n]();

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 0; i < n; i++) {
        if (arr[i] == 0) {
            reverse(arr, arr + i);
        }
    }

    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}