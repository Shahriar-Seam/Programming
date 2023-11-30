#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k, i, cnt, *arr;

    cin >> t;

    while (t--) {
        cin >> n >> k;

        arr = new int[n];
        
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cnt = 0;

        for (i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                cnt = 5;
                break;
            }
        }

        if (cnt != 0 && k <= 1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }

        delete[] arr;
    }
}