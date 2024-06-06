#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    cin >> n;

    int arr[n];
    int arr2[n];

    for (i = 1; i < n; i++) {
        cin >> arr[i];
    }

    arr2[0] = 1e7;

    for (i = 1; i < n; i++) {
        arr2[i] = arr[i] + arr2[i - 1];

        // if (arr2[i] % arr2[i - 1] != arr[i]) {
        //     // arr2[i - 1] += arr2[i - 2] * arr[i];
        // }

        // if (i < n - 1 && arr2[i] < arr[i + 1]) {
        //     arr2[i] += arr2[i - 1] * arr[i + 1];
        // }
    }

    for (i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }

    cout << "\n";

    // for (i = 0; i < n - 1; i++) {
    //     cout << arr2[i + 1] % arr2[i] << " ";
    // }

    // cout << "\n";
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