#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, temp;

    cin >> t;

    while (t--) {
        vector <int> arr;

        cin >> n;

        for (i = 0; i < n; i++) {
            cin >> temp;

            arr.push_back(temp);
        }

        if (arr[0] == 1) {
            sort(arr.begin() + 1, arr.end());

            if (arr.back() == n) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}