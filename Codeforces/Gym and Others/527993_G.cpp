#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j;
    int arr[20][20] = {};

    cin >> n;

    if (floor(log2(n)) == ceil(log2(n))) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cout << n << " ";
            }

            cout << "\n";
        }
    }
    else {
        cout << -1 << "\n";
    }

    return 0;
}