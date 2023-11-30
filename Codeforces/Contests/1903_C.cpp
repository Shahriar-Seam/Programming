#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t, n, *arr, i, sum, t_sum, index;

    cin >> t;

    while (t--) {
        cin >> n;

        arr = new long long[n];
        sum = t_sum = 0;

        for (i = 0; i < n; i++) {
            cin >> arr[i];

            sum += arr[i] * (i + 1);
        }

        if (arr[n - 1] < 0) {
            sum = 0;

            for (i = n - 1; i >= 0; i--) {
                t_sum += arr[i];

                if (t_sum >= 0) {
                    index = i;
                    break;
                }
            }

            sum = t_sum * (index + 1);

            for (i = 0; i < index; i++) {
                sum += arr[i] * (i + 1);
            }
        }

        cout << sum << "\n";

        delete[] arr;
    }

    return 0;
}