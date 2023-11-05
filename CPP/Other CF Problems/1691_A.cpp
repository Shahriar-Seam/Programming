#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, *arr, i, c1, c2, d = 2;

    cin >> t;

    while (t--) {
        cin >> n;

        arr = new int[n];

        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }

        c1 = count_if(arr, arr + n, [d](int x) { return x % d == 0; });
        c2 = n - c1;

        cout << min({c1, c2}) << "\n";

        delete arr;
    }

    return 0;
}