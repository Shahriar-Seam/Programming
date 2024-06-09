#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, temp;
    long long c = 0, sum = 0;
    vector <int> v;

    cin >> n;

    long long arr[4][n];

    for (i = 0; i < n; i++) {
        cin >> temp;

        v.push_back(temp);
    }

    arr[0][0] = v[0];
    arr[1][0] = abs(v[0]);
    arr[2][0] = abs(v[0]);
    arr[3][0] = v[0];

    for (i = 1; i < n; i++) {
        arr[0][i] = arr[0][i - 1] + v[i];
        arr[1][i] = abs(arr[1][i - 1] + v[i]);
        arr[2][i] = max(arr[0][i], arr[1][i]);
        arr[3][i] = min(arr[0][i], arr[1][i]);
    }

    cout << arr[3][n - 1] << "\n";
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