#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, s, i, j, k, found;
    int *arr;

    cin >> t;

    while (t--) {
        cin >> n >> s;

        arr = new int[n];

        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }

        found = 0;

        for (i = 0; i < n - 2; i++) {
            for (j = i + 1; j < n - 1; j++) {
                for (k = j + 1; k < n; k++) {
                    if (arr[i] + arr[j] + arr[k] == s) {
                        found = 1;
                        break;
                    }
                }
            }
        }

        found ? cout << "YES\n" : cout << "NO\n";

        delete[] arr;
    }

    return 0;
}