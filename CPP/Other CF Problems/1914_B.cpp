#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k, i;
    vector <int> arr;

    cin >> t;

    while (t--) {
        cin >> n >> k;

        for (i = 0; i < n; i++) {
            arr.push_back(i + 1);
        }

        reverse(arr.begin() + k, arr.end());

        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }

        cout << "\n";

        arr.clear();
    }

    return 0;
}