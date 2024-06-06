#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, j, k;

    cin >> t;

    while (t--) {
        cin >> n;

        for (i = 1; i <= n; i++) {
            for (j = 0; j < i; j++) {
                cout << "*";
            }

            for (k = 0; k < 2 * n - 2 * i; k++) {
                cout << "#";
            }

            for (j = 0; j < i; j++) {
                cout << "*";
            }

            cout << "\n";
        }

        cout << "\n";
    }

    return 0;
}