#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, *arr, i, j, sum, m = 1000000000;

    cin >> n;

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (i = 0, sum = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            sum = arr[i] + arr[j] + j - i;

            if (sum < m) {
                m = sum;
            }
        }
    }

    cout << m << "\n";

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