#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, *arr, *arr1, i, m1, m2;

    cin >> t;

    while (t--) {
        cin >> n;

        arr = new int[n];
        arr1 = new int[n]();

        for (i = 0; i < n; i++) {
            cin >> arr[i];

            arr1[i] = arr[i];
        }

        sort(arr1, arr1 + n);

        m1 = arr1[n - 1];
        m2 = arr1[n - 2];

        for (i = 0; i < n; i++) {
            if (arr[i] == m1) {
                cout << arr[i] - m2 << " ";
            }
            else {
                cout << arr[i] - m1 << " ";
            }
        }

        cout << "\n";

        delete[] arr;
        delete[] arr1;
    }

    return 0;
}