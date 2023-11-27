#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, temp, i, j, k, sum;
    vector <int> arr;

    cin >> t;

    while (t--) {
        cin >> n;

        sum = 0;

        for (i = 0; i < n; i++) {
            cin >> temp;

            arr.push_back(temp);
        }

        sort(arr.begin(), arr.end());

        for (i = 0; i < n - 2; i++) {
            for (j = i + 1; j < n - 1; j++) {
                for (k = j + 1; k < n; k++) {
                    sum += gcd(arr[i], arr[j]);
                }
            }
        }

        cout << sum << "\n";

        arr.clear();
    }

    return 0;
}