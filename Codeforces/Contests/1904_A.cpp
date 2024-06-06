#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t, n, temp, i, j, cnt, sum, f;

    cin >> t;

    while (t--) {
        cin >> n;

        vector <long long> arr;
        vector <long long> arr2;

        for (i = 0; i < n; i++) {
            cin >> temp;

            arr.push_back(temp);
            arr2.push_back(temp);
        }

        sort(arr2.begin(), arr2.end());

        for (i = 0; i < n; i++) {
            sum = arr[i];
            j = f = cnt = 0;

            while (j < n) {
                if (sum < arr2[j]) {
                    break;
                }
                else {
                    sum += arr2[j];
                    cnt++;
                }
                if (f == 0 && arr[i] == arr2[j]) {
                    f = 1;
                    sum -= arr2[j];
                    cnt--;
                }

                j++;
            }

            cout << cnt << " ";
        }

        cout << "\n";
    }

    return 0;
}