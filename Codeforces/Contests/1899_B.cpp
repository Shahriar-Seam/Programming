#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, j, *arr, sum1, sum2, m;

    cin >> t;

    while (t--) {
        cin >> n;

        arr = new int[n];
        m = 0;

        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for (i = 0; i < n; i++) {
            sum1 = sum2 = 0;
            
            for (j = 0; j <= i; j++) {
                sum1 += arr[j];
            }
            for (k = )

            if (abs(sum2 - sum1) > m) {
                m = abs(sum2 - sum1);
            }
        }

        cout << m << "\n";

        delete[] arr;
    }

    return 0;
}