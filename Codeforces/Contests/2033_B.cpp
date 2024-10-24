#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, k, min_val, l, r;
    long long sum = 0;

    cin >> n;

    int arr[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (k = 0, j = 0; k < n; k++, j++) {
        min_val = 1e9;

        for (l = 0, r = j; l < n && r < n; l++, r++) {
            min_val = min(min_val, arr[l][r]);
        }

        sum -= min(0, min_val);
    }
    
    for (k = 1, j = 1; k < n; k++, j++) {
        l = k, r = j;

        min_val = 1e9;

        for (l = k, r = 0; l < n && r < n; l++, r++) {
            min_val = min(min_val, arr[l][r]);
        }

        sum -= min(0, min_val);
    }

    cout << sum << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}