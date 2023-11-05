#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, *arr, i, m, cnt;

    cin >> t;

    while (t--) {
        cin >> n;

        arr = new int[n];

        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }

        m = *min_element(arr, arr + n);
        cnt = count_if(arr, arr + n, [m](int x) {return x > m; });

        cout << cnt << "\n";
    }

    return 0;
}