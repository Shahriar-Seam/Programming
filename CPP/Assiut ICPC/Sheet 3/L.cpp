#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, *arr, i, j, k, m;

    cin >> n;

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            m = -1000000;

            for (k = i; k <= j; k++) {
                if (arr[k] > m) {
                    m = arr[k];
                }
            }

            cout << m << " ";
        }
    }

    cout << "\n";

    free(arr);
}

int main()
{
    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}