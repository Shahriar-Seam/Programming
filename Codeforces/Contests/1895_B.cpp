#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, *arr, i, s1, s2;

    cin >> t;

    while (t--) {
        cin >> n;

        arr = new int[2 * n];
        s1 = s2 = 0;

        for (i = 0; i < 2 * n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + 2 * n);

        for (i = 0; i < n - 1; i++) {
            s1 += abs(arr[i] - arr[i + 1]);
        }
        for (i = n; i < 2 * n - 1; i++) {
            s2 += abs(arr[i] - arr[i + 1]);
        }

        cout << s1 + s2 << "\n";

        for (i = 0; i < n; i++) {
            cout << arr[i] << " " << arr[2 * n - i - 1] << "\n";
        }

        delete[] arr;
    }

    return 0;
}