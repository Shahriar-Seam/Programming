#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, *arr, i;

    cin >> t;

    while (t--) {
        cin >> n;

        arr = new int[n];

        fill(arr, arr + n, n);

        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }

        cout << "\n";
    }

    return 0;
}