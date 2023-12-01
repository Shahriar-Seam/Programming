#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, k, m;

    cin >> n;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            m = min(i, j);
            k = n - m + 1;

            cout << k << " ";
        }
        for (j = n - 1; j >= 1; j--) {
            m = min(i, j);
            k = n - m + 1;

            cout << k << " ";
        }

        cout << "\n";
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= n; j++) {
            m = min(i, j);
            k = n - m + 1;

            cout << k << " ";
        }
        for (j = n - 1; j >= 1; j--) {
            m = min(i, j);
            k = n - m + 1;

            cout << k << " ";
        }

        cout << "\n";
    }

    return 0;
}